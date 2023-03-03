#pragma once

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

/***CHECK***/

// not fixable (has no corresponding void function to fix)
bool areBracketsOK(std::string_view str);
bool areOuterOperatorsLegal(std::string_view str);
bool areOperatorsLegal(std::string_view str);
bool areCharsSupported(std::string_view str);

// fixable (has corresponding void function to fix)
bool hasRedundantSigns(std::string_view str);
bool hasNumberNextToBracket(std::string_view str);
bool hasDoubleAsterisks(std::string_view str);
bool hasCommas(std::string_view str);
bool hasInvalidBrackets(std::string_view str);
bool hasBackslashes(std::string_view str);

// other
bool hasPercentSign(std::string_view str);

bool doesUserInputNeedAutoRepair(std::string_view str);
bool isUserInputBrokenBeyondAutoRepair(std::string_view str);

// conditional fixes
void simplifyDoubleSigns(std::string &str);
void trimRedundantPluses(std::string &str);
void treatSymbolsNextToBracketAsMultiplication(std::string &str);
void replaceAsterisksWithCarets(std::string &str);
void replaceCommasWithPeriods(std::string &str);
void standardizeBrackets(std::string &str);
void replaceBackslashWithForwardSlash(std::string &str);

// other

void treatPercentAsDivisionByOneHundred(std::string &str);
void treatPercentAsDivisionWithRemainder(std::string &str);

void autoRepairUserInput(std::string &str);

// unused
void filterInvalidChars(std::string &str);