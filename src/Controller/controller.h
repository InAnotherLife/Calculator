#ifndef SRC_CONTROLLER_CONTROLLER_H_
#define SRC_CONTROLLER_CONTROLLER_H_

#include <memory>

#include "../Model/calculator.h"

namespace my {

class Controller {
 public:
  string GetResult(const std::string *input_expr);

 private:
  std::unique_ptr<Calculator> calculator_;
};

}  // namespace my

#endif  // SRC_CONTROLLER_CONTROLLER_H_
