#include "calculator.h"

namespace my {

int_type Calculator::GetPreviousSym(int_type num) {
  return (num > 0 ? input_expr_[num - 1] : 32);
}

int_type Calculator::GetCurrentSym(int_type num) { return input_expr_[num]; }

int_type Calculator::GetSecondSym(int_type num) {
  return (num + 1 <= input_expr_len_ ? input_expr_[num + 1] : 32);
}

int_type Calculator::GetThirdSym(int_type num) {
  return (num + 2 <= input_expr_len_ ? input_expr_[num + 2] : 32);
}

int_type Calculator::GetFourthSym(int_type num) {
  return (num + 3 <= input_expr_len_ ? input_expr_[num + 3] : 32);
}

void Calculator::ReplaceFuncToSym() {
  for (int_type i = 0; i <= input_expr_.length(); i++) {
    if (GetCurrentSym(i) == 'c' && GetSecondSym(i) == 'o' &&
        GetThirdSym(i) == 's')
      input_expr_.replace(i, 3, "a");
    else if (GetCurrentSym(i) == 's' && GetSecondSym(i) == 'i' &&
             GetThirdSym(i) == 'n')
      input_expr_.replace(i, 3, "b");
    else if (GetCurrentSym(i) == 't' && GetSecondSym(i) == 'a' &&
             GetThirdSym(i) == 'n')
      input_expr_.replace(i, 3, "c");
    else if (GetCurrentSym(i) == 'a' && GetSecondSym(i) == 'c' &&
             GetThirdSym(i) == 'o' && GetFourthSym(i) == 's')
      input_expr_.replace(i, 4, "d");
    else if (GetCurrentSym(i) == 'a' && GetSecondSym(i) == 't' &&
             GetThirdSym(i) == 'a' && GetFourthSym(i) == 'n')
      input_expr_.replace(i, 4, "f");
    else if (GetCurrentSym(i) == 's' && GetSecondSym(i) == 'q' &&
             GetThirdSym(i) == 'r' && GetFourthSym(i) == 't')
      input_expr_.replace(i, 4, "g");
    else if (GetCurrentSym(i) == 'l' && GetSecondSym(i) == 'n')
      input_expr_.replace(i, 2, "h");
    else if (GetCurrentSym(i) == 'l' && GetSecondSym(i) == 'o' &&
             GetThirdSym(i) == 'g')
      input_expr_.replace(i, 3, "i");
    else if (GetCurrentSym(i) == 'a' && GetSecondSym(i) == 's' &&
             GetThirdSym(i) == 'i' && GetFourthSym(i) == 'n')
      input_expr_.replace(i, 4, "j");
    else if (GetCurrentSym(i) == 'e' && GetSecondSym(i) == 'x' &&
             GetThirdSym(i) == 'p')
      input_expr_.replace(i, 3, "l");
    else if (GetCurrentSym(i) == 'e' && GetSecondSym(i) == '+')
      input_expr_.replace(i, 2, "x");
    else if (GetCurrentSym(i) == 'e' && GetSecondSym(i) == '-')
      input_expr_.replace(i, 2, "y");
    else if (GetCurrentSym(i) == 'm' && GetSecondSym(i) == 'o' &&
             GetThirdSym(i) == 'd')
      input_expr_.replace(i, 3, "z");
  }
}

short int Calculator::GetPriority(int_type sym) {
  short int result = 0;
  if (sym == '(')
    result = -1;
  else if (sym >= 'a' && sym <= 'w')
    result = 1;
  else if (sym >= 'x' && sym <= 'z')
    result = 2;
  else if (sym == '^')
    result = 3;
  else if (sym == '*' || sym == '/')
    result = 4;
  else if (sym == '+' || sym == '-')
    result = 5;
  return result;
}

bool Calculator::IsNumOrDot(int_type sym) {
  return (std::isdigit(sym) || sym == '.');
}

bool Calculator::IsFunc(int_type sym) { return (sym >= 'a' && sym <= 'w'); }

void Calculator::IsNanOrInf() {
  if (std::isnan(stack_num_.top()) || std::isinf(stack_num_.top()))
    error_num_ = 2;
}

int_type Calculator::CountSym(int_type num) {
  int_type CountSym = 0;
  for (int_type i = 0; i < input_expr_.length(); i++) {
    if (GetCurrentSym(i) == num) CountSym++;
  }
  return CountSym;
}

void Calculator::GetData(const string *expr) {
  input_expr_len_ = expr->length();
  if (input_expr_len_ > MAX_SIZE_EXPR) error_num_ = 3;
  input_expr_ = *expr;
  if (input_expr_[0] == '\0') stack_num_.push(0);
}

void Calculator::ClearVar() {
  stack_num_ = stack<double>();
  stack_opt_ = stack<int_type>();
  input_expr_.clear();
  error_num_ = 0;
  input_expr_len_ = 0;
}

void Calculator::ReturnResult(string *result) {
  if (error_num_ == 0) {
    std::stringstream buffer;
    buffer << std::fixed << std::setprecision(7) << stack_num_.top();
    *result = buffer.str();
  } else if (error_num_ == 1) {
    *result = "Syntax error";
  } else if (error_num_ == 2) {
    *result = "Math error";
  } else if (error_num_ == 3) {
    *result = "The string is more than 250 symbols";
  }
}

}  // namespace my
