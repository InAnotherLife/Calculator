#include "calculator.h"

namespace my {

void Calculator::GetOpt() {
  int_type sign = 0;
  double num_1 = 0, num_2 = 0;
  sign = stack_opt_.top();
  stack_opt_.pop();
  num_2 = stack_num_.top();
  stack_num_.pop();
  if (!stack_num_.empty() && (sign < 'a' || sign >= 'x')) {
    num_1 = stack_num_.top();
    stack_num_.pop();
  }
  GetResult(sign, num_1, num_2);
}

void Calculator::GetResult(int_type sign, double num_1, double num_2) {
  if (sign == '+')
    stack_num_.push(num_1 + num_2);
  else if (sign == '-')
    stack_num_.push(num_1 - num_2);
  else if (sign == '*')
    stack_num_.push(num_1 * num_2);
  else if (sign == '/')
    stack_num_.push(num_1 / num_2);
  else if (sign == '^')
    stack_num_.push(pow(num_1, num_2));
  else if (sign == 'a')
    stack_num_.push(cos(num_2));
  else if (sign == 'b')
    stack_num_.push(sin(num_2));
  else if (sign == 'c')
    stack_num_.push(tan(num_2));
  else if (sign == 'd')
    stack_num_.push(acos(num_2));
  else if (sign == 'f')
    stack_num_.push(atan(num_2));
  else if (sign == 'g')
    stack_num_.push(sqrt(num_2));
  else if (sign == 'h')
    stack_num_.push(log(num_2));
  else if (sign == 'i')
    stack_num_.push(log10(num_2));
  else if (sign == 'j')
    stack_num_.push(asin(num_2));
  else if (sign == 'l')
    stack_num_.push(exp(num_2));
  else if (sign == 'x')
    stack_num_.push(num_1 * pow(10, num_2));
  else if (sign == 'y')
    stack_num_.push(num_1 * pow(10, num_2 * -1));
  else if (sign == 'z')
    stack_num_.push(fmod(num_1, num_2));
}

void Calculator::ParseNum(int_type sym) {
  static string tmp_num;
  static int_type dot_count = 0;
  static bool tmp_num_flag = false;
  if (IsNumOrDot(sym)) {
    if (sym == '.') dot_count++;
    if (dot_count > 1) error_num_ = 1;
    tmp_num.push_back(sym);
    tmp_num_flag = true;
  }
  if (tmp_num_flag && (!IsNumOrDot(sym) || sym == '\0')) {
    stack_num_.push(std::stod(tmp_num));
    dot_count = 0;
    tmp_num_flag = false;
    tmp_num.clear();
  }
}

void Calculator::ParseMinus(int_type prev_sym, int_type curr_sym,
                            int_type second_sym) {
  if (stack_opt_.top() == '^' && curr_sym == '#') {
    double tmp_num = stack_num_.top();
    stack_num_.pop();
    stack_num_.push(1 / tmp_num);
  }
  if (stack_opt_.top() == 'g' && curr_sym == '#') {
    stack_num_.push(0);
    stack_opt_.push('-');
  }
  if ((IsFunc(prev_sym) || prev_sym == '*' || prev_sym == '/') &&
      curr_sym == '#' && prev_sym != 'g') {
    stack_num_.push(-1);
    stack_opt_.push('*');
  }
  if ((curr_sym == '*' || curr_sym == '/') && stack_opt_.top() == '-')
    NumToMinusNum();
  if (curr_sym == '^' && stack_opt_.top() == '-' && second_sym % 2 != 0)
    NumToMinusNum();
}

void Calculator::ParseOpt(int_type sym, short int head_stack_priority,
                          short int current_sym_priority) {
  if (current_sym_priority < head_stack_priority && sym != ')' && sym != '#')
    stack_opt_.push(sym);
  if (current_sym_priority == head_stack_priority && sym != '#') {
    if (sym != '(' && sym != '^')
      // if (sym != '(') // В том случае,
      // если ^ - левоассоциативный оператор, т.е. 2^3^4 = 4096
      GetOpt();
    stack_opt_.push(sym);
  }
  if (current_sym_priority > head_stack_priority && sym != ')' && sym != '#') {
    if (stack_opt_.top() != '(') {
      while (current_sym_priority > GetPriority(stack_opt_.top()) &&
             stack_opt_.top() != '(') {
        GetOpt();
        if (stack_opt_.empty() || stack_opt_.top() == '(') break;
      }
    }
    stack_opt_.push(sym);
  }
}

void Calculator::NumToMinusNum() {
  double tmp_num = stack_num_.top();
  stack_num_.pop();
  stack_num_.push(tmp_num * -1);
  stack_opt_.pop();
  stack_opt_.push('+');
}

string Calculator::CalculateResult(const string *input_expr) {
  string result;
  GetData(input_expr);
  CheckBracket();
  ReplaceFuncToSym();
  CheckMult();
  CheckScientificNotation();
  CheckUnaryPlusMinus();
  FirtsCheckInputExpr();
  SecondCheckInputExpr();
  if (error_num_ == 0) {
    short int head_stack_priority = 0, current_sym_priority = 0;
    for (int_type i = 0; i <= input_expr_.length(); i++) {
      ParseNum(GetCurrentSym(i));
      if (!IsNumOrDot(GetCurrentSym(i)) && GetCurrentSym(i) != '\0') {
        if (stack_opt_.empty()) {
          stack_opt_.push(GetCurrentSym(i));
          continue;
        }
        head_stack_priority = GetPriority(stack_opt_.top());
        current_sym_priority = GetPriority(GetCurrentSym(i));
        ParseMinus(GetPreviousSym(i), GetCurrentSym(i), GetSecondSym(i));
        if (GetCurrentSym(i) == ')') {
          while (stack_opt_.top() != '(') GetOpt();
          stack_opt_.pop();
        }
        ParseOpt(GetCurrentSym(i), head_stack_priority, current_sym_priority);
      }
      if (GetCurrentSym(i) == '\0') {
        while (!stack_opt_.empty()) GetOpt();
        IsNanOrInf();
      }
    }
  }
  ReturnResult(&result);
  ClearVar();
  return result;
}

}  // namespace my
