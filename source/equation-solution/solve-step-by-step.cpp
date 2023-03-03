#include "../shared.hpp"
#include "solve.hpp"

#include <cassert>
#include <cmath>

std::string copyValueFromLeft(long long pos, std::string str) {
  for (long long i{pos - 1}; i >= -1; --i) {
    if (i == -1 || isERMDAS(str[i])) {
      long long length{pos - i - 1};
      if (str[i] == '-') {
        length = pos - i;
        return str.substr(i, length);
      }
      return str.substr(i + 1, length);
    }
  }
  return "";
}

std::string copyValueFromRight(std::size_t pos, std::string str) {
  std::size_t i{pos + 1};
  if (i == '-') {
    i = pos + 2;
  }
  for (; i <= str.size(); ++i) {
    if (i == str.size() || isERMDAS(str[i])) {
      std::size_t length{i - pos - 1};
      return str.substr(pos + 1, length);
    }
  }
  return "";
}

double calculate(SingleExpression expr) {

  double leftOperand{std::stod(expr.leftOperand)};
  double rightOperand{std::stod(expr.rightOperand)};
  switch (expr.operation) {
  case '^':
    return std::pow(leftOperand, rightOperand);
  case '%':
    return std::fmod(leftOperand, rightOperand);
  case '*':
    return leftOperand * rightOperand;
  case '/':
    return leftOperand / rightOperand;
  case '+':
    return leftOperand + rightOperand;
  case '-':
    return leftOperand - rightOperand;
  default:
    assert(expr.operation && "Unrecognized operation");
    return 0;
  }
}

std::string copyMostSignificantParent(std::string str) {
  for (std::size_t i{0}; i < str.size(); ++i) {
    if (str[i] == ')') {
      for (long long j{static_cast<long long>(i)}; j >= -1; --j) {
        if (str[j] == '(') {
          std::size_t length{i - j - 2};
          return str.substr(j + 1, length);
        }
      }
    }
  }
  return "";
}

void solveEquation(std::string &str) {
  SingleExpression expr{"0", '+', "0"};
  for (std::string_view operation : orderOfOperations) {
    for (std::size_t i{1}; i < str.size(); ++i) {
      if (doesCharMatchPattern(str[i], operation)) {
        expr = {copyValueFromLeft(i, str), str[i], copyValueFromRight(i, str)};

        std::string str_result{std::to_string(calculate(expr))};
        removeTrailingZeros(str_result);

        std::size_t swap_starting_position{i - expr.leftOperand.length()};
        std::size_t swap_length{expr.leftOperand.length() +
                                expr.rightOperand.length() + 1};

        str.erase(swap_starting_position, swap_length);
        str.insert(swap_starting_position, str_result);
        i = 0;
      }
    }
  }
}