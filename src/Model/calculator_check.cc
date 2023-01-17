#include "calculator.h"

namespace my {

void Calculator::CheckBracket() {
  bool bracket_flag = false;
  for (int_type i = 0; i <= input_expr_.length(); i++) {
    if (GetCurrentSym(i) == '(')
      bracket_flag = true;
    else if (GetCurrentSym(i) == ')')
      bracket_flag = false;
  }
  if (CountSym('(') != CountSym(')') || bracket_flag) error_num_ = 1;
}

void Calculator::CheckMult() {
  for (int_type i = 0; i <= input_expr_.length(); i++) {
    if (GetCurrentSym(i) == ')' && GetSecondSym(i) == '(')
      input_expr_.insert(i + 1, "*");
    if (IsNumOrDot(GetCurrentSym(i)) && GetSecondSym(i) == '(')
      input_expr_.insert(i + 1, "*");
    if (GetCurrentSym(i) == ')' &&
        (IsNumOrDot(GetSecondSym(i)) || IsFunc(GetSecondSym(i))))
      input_expr_.insert(i + 1, "*");
    if (GetCurrentSym(i) == 'e' &&
        (GetSecondSym(i) != '+' || GetSecondSym(i) != '-'))
      error_num_ = 1;
    if (GetCurrentSym(i) == '*' || GetCurrentSym(i) == '/') {
      if (GetSecondSym(i) == '-')
        input_expr_.replace(i + 1, 1, "#");
      else if (!IsNumOrDot(GetSecondSym(i)) && GetSecondSym(i) != '(' &&
               !IsFunc(GetSecondSym(i)) && GetSecondSym(i) != '#')
        error_num_ = 1;
      else if ((GetSecondSym(i) == '0' && GetThirdSym(i) == '-') ||
               (GetSecondSym(i) == '0' && GetThirdSym(i) == '+'))
        error_num_ = 1;
      else if (!IsNumOrDot(GetPreviousSym(i)) && GetPreviousSym(i) != ')')
        error_num_ = 1;
    }
  }
}

void Calculator::CheckUnaryPlusMinus() {
  for (int_type i = 0; i <= input_expr_.length(); i++) {
    if (GetCurrentSym(i) == '+' || GetCurrentSym(i) == '-') {
      if (!IsNumOrDot(GetPreviousSym(i)) && GetPreviousSym(i) != ')' &&
          GetPreviousSym(i) != '^' && !IsFunc(GetPreviousSym(i)))
        input_expr_.insert(i, "0");
    }
  }
}

void Calculator::CheckScientificNotation() {
  for (int_type i = 0; i <= input_expr_.length(); i++) {
    if ((GetCurrentSym(i) == 'x' || GetCurrentSym(i) == 'y') &&
        (!IsNumOrDot(GetPreviousSym(i)) || !IsNumOrDot(GetSecondSym(i))))
      error_num_ = 1;
  }
}

void Calculator::FirtsCheckInputExpr() {
  for (int_type i = 0; i <= input_expr_.length(); i++) {
    if (IsNumOrDot(GetCurrentSym(i)) && IsFunc(GetSecondSym(i))) error_num_ = 1;
    if (GetCurrentSym(i) == 'z' && !IsNumOrDot(GetPreviousSym(i)))
      error_num_ = 1;
    if (GetCurrentSym(i) == '+' || GetCurrentSym(i) == '-') {
      if (!IsNumOrDot(GetSecondSym(i)) && GetSecondSym(i) != '(' &&
          !IsFunc(GetSecondSym(i)))
        error_num_ = 1;
    }
    if (IsFunc(GetCurrentSym(i))) {
      if (!IsNumOrDot(GetSecondSym(i)) && GetSecondSym(i) != '(' &&
          GetSecondSym(i) != '-')
        error_num_ = 1;
      else if (GetSecondSym(i) == '-' && IsNumOrDot(GetThirdSym(i)))
        input_expr_.replace(i + 1, 1, "#");
    }
  }
}

void Calculator::SecondCheckInputExpr() {
  for (int_type i = 0; i <= input_expr_.length(); i++) {
    if (GetCurrentSym(i) == '.' &&
        (!IsNumOrDot(GetPreviousSym(i)) || !IsNumOrDot(GetSecondSym(i))))
      error_num_ = 1;
    if (GetCurrentSym(i) == '(' && !IsNumOrDot(GetSecondSym(i)) &&
        GetSecondSym(i) != '(' && !IsFunc(GetSecondSym(i)))
      error_num_ = 1;
    if (GetCurrentSym(i) == '^') {
      if (!IsNumOrDot(GetPreviousSym(i)) && GetPreviousSym(i) != ')')
        error_num_ = 1;
      else if (!IsNumOrDot(GetSecondSym(i)) && GetSecondSym(i) != '(' &&
               !IsFunc(GetSecondSym(i)) && GetSecondSym(i) != '-')
        error_num_ = 1;
      else if (GetSecondSym(i) == '-')
        input_expr_.replace(i + 1, 1, "#");
    }
  }
}

}  // namespace my
