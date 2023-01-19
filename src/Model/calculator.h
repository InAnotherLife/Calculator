#ifndef SRC_MODEL_CALC_H_
#define SRC_MODEL_CALC_H_

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

constexpr unsigned short int MAX_SIZE_EXPR = 250;

using std::stack;
using std::string;
using int_type = unsigned short int;

namespace my {

class Calculator {
 public:
  Calculator() : error_num_(0), input_expr_len_(0) {}
  string CalculateResult(const string *input_expr);

 private:
  stack<double> stack_num_;
  stack<int_type> stack_opt_;
  string input_expr_;
  int_type error_num_;
  int_type input_expr_len_;
  void ReplaceFuncToSym();
  void CheckBracket();
  void CheckMult();
  void CheckUnaryPlusMinus();
  void CheckScientificNotation();
  void FirtsCheckInputExpr();
  void SecondCheckInputExpr();
  int_type GetPreviousSym(int_type num);
  int_type GetCurrentSym(int_type num);
  int_type GetSecondSym(int_type num);
  int_type GetThirdSym(int_type num);
  int_type GetFourthSym(int_type num);
  short int GetPriority(int_type sym);
  bool IsNumOrDot(int_type sym);
  bool IsFunc(int_type sym);
  void IsNanOrInf();
  int_type CountSym(int_type sym);
  void ParseNum(int_type sym);
  void ParseMinus(int_type prev_sym, int_type curr_sym, int_type next_sym);
  void ParseOpt(int_type sym, short int head_stack_priority,
                short int current_sym_priority);
  void GetOpt();
  void NumToMinusNum();
  void GetResult(int_type sign, double num_1, double num_2);
  void GetData(const string *expr);
  void ClearVar();
  void ReturnResult(string *result);
};

}  // namespace my

#endif  // SRC_MODEL_CALC_H_
