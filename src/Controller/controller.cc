#include "controller.h"

namespace my {

string Controller::GetResult(const std::string *input_expr) {
  calculator_ = std::make_unique<Calculator>();
  return calculator_->CalculateResult(input_expr);
}

}  // namespace my
