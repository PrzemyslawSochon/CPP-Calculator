#pragma once

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>

void removeTrailingZeros(std::string &str_value);
void printCaretUnderIssue(const std::size_t &i1, const std::size_t &i2);

constexpr std::array<std::string_view, 4> orderOfOperations{"^", "%", "/*",
                                                            "+-"};
constexpr std::string_view supportedCharactersArray{
    "0123456789^%/\\*+-()[]{}., \t\n"};

struct SingleExpression {
  std::string leftOperand{};
  char operation{};
  std::string rightOperand{};
};

inline void trimWhiteSpaces(std::string &str) {
  str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

inline bool doesCharMatchPattern(char c, std::string_view str) {
  return str.find(c) != std::string_view::npos;
}

// note ASCII only
inline bool isAlphanumeric(char c) {
  return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
         (c >= 'a' && c <= 'z');
}

inline bool isAnyOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ||
          c == '%' || c == '!');
}

// exponent, remainder, multiplication, division, addition, subtraction
inline bool isERMDAS(char c) {
  return (c == '^' || c == '%' || c == '*' || c == '/' || c == '+' || c == '-');
}

// exponent, remainder, multiplication, division, addition, subtraction
inline bool isERMDA(char c) {
  return (c == '^' || c == '%' || c == '*' || c == '/' || c == '+');
}

// exponent, factorial, remainder, multiplication, division
inline bool isEFRMD(char c) {
  return (c == '^' || c == '!' || c == '%' || c == '*' || c == '/');
}

// exponent, remainder, multiplication, division
inline bool isERMD(char c) {
  return (c == '^' || c == '%' || c == '*' || c == '/');
}

inline bool areParentsStillAround(std::string_view str) {
  for (const char &c : str) {
    if (c == ')') {
      return true;
    }
  }
  return false;
}