#pragma once
#include <string>

std::string copyValueFromLeft(long long pos, std::string str);
std::string copyValueFromRight(std::size_t pos, std::string str);
double calculate(SingleExpression expr);
std::string copyMostSignificantParent(std::string str);
void solveEquation(std::string &str);