#include "../shared.hpp"
#include "equation.hpp"
#include <vector>

void trimRedundantPluses(std::string &str)
{
    if (str[0] == '+')
    {
        str.erase(0, 1);
    }

    std::vector<std::pair<char, char>> redundantPluses = {
        {'-', '+'},
        {'+', '+'},
        {'(', '+'},
        {'^', '+'},
        {'*', '+'},
        {'/', '+'},
    };

    for (std::size_t i{0}; i < str.size() - 1; ++i)
    {
        auto it = std::find_if(redundantPluses.begin(), redundantPluses.end(),
                               [str, i](const auto &sign)
                               { return sign == std::make_pair(str[i], str[i + 1]); });
        if (it != redundantPluses.end())
        {
            str.erase(i + 1, 1);
            --i;
        }
    }

    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Trimmed redundant pluses.\n";
    // }
}

void simplifyDoubleSigns(std::string &str)
{
    for (std::size_t i{0}; i < str.size() - 1; ++i)
    {
        if (str[i] == '-' && str[i + 1] == '-')
        {
            str.erase(i, 2);
            str.insert(i, "+");
            --i;
        }
        else if (str[i] == '-' && str[i + 1] == '+')
        {
            str.erase(i, 2);
            str.insert(i, "-");
            --i;
        }
        else if (str[i] == '+' && str[i + 1] == '-')
        {
            str.erase(i, 2);
            str.insert(i, "-");
            --i;
        }
    }

    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Simplified pluses and minuses.\n";
    // }
}

void treatSymbolsNextToBracketAsMultiplication(std::string &str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (str[i] == '(' && i > 0 && isAlphanumeric(str[i - 1]))
        {
            str.insert(i, "*");
            ++i;
        }
        else if (str[i] == ')' && i < str.size() - 1 && isAlphanumeric(str[i + 1]))
        {
            str.insert(i + 1, "*");
            ++i;
        }
    }
    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Handled adjacent symbols to parenthesis.\n";
    // }
}

void replaceAsterisksWithCarets(std::string &str)
{
    for (std::size_t i{0}; i < str.size() - 1; ++i)
    {
        if (str[i] == '*' && str[i + 1] == '*')
        {
            str.erase(i, 2);
            str.insert(i, "^");
            --i;
        }
    }
    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Replaced all of double asterisks `**` with caret signs `^`.\n";
    // }
}

void replaceCommasWithPeriods(std::string &str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (str[i] == ',')
        {

            str.erase(i, 1);
            str.insert(i, ".");
        }
    }
    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Swapped all occurrences of commas `,` to dots `.`\n";
    // }
}

void standardizeBrackets(std::string &str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (str[i] == '[' || str[i] == '{')
        {
            str.erase(i, 1);
            str.insert(i, "(");
        }
        else if (str[i] == ']' || str[i] == '}')
        {
            str.erase(i, 1);
            str.insert(i, ")");
        }
    }
    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Replaced all occurrences of bracket `[]` `{}` with parenthesis `()`\n";
    // }
}

void replaceBackslashWithForwardSlash(std::string &str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (str[i] == '\\')
        {
            str.erase(i, 1);
            str.insert(i, "/");
        }
    }
    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Swapped all occurrences of backward slashes `\\` to forward slashes `/`.\n";
    // }
}

void treatPercentAsDivisionByOneHundred(std::string &str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (str[i] == '%')
        {
            str.erase(i, 1);
            str.insert(i, "/100");
            i = i + 3;
        }
    }
    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Replaced percent sign with /100.\n";
    // }
}

void treatPercentAsDivisionWithRemainder(std::string &str)
{
    std::cout << "Treating percent sign as division with remainder.\n";
    return;
}

void autoRepairUserInput(std::string &str)
{
    trimWhiteSpaces(str);
    treatSymbolsNextToBracketAsMultiplication(str);
    trimRedundantPluses(str);
    simplifyDoubleSigns(str);
    replaceAsterisksWithCarets(str);
    replaceCommasWithPeriods(str);
    standardizeBrackets(str);
    replaceBackslashWithForwardSlash(str);

    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "End of auto repair\n";
    // }
}

// void parseUserInput(std::string &str)
// {
//     if (g_treat_percent_sign_as == Percent::decimal)
//     {
//         treatPercentAsDivisionByOneHundred(str);
//     }
//     if (!g_automatically_fix_errors && doesUserInputNeedAutoRepair(str))
//     {
//         askUserToHandleBadInput();
//     }
//     autoRepairUserInput(str);
// }

void filterInvalidChars(std::string &str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (!doesCharMatchPattern(str[i], supportedCharactersArray ))
        {
            str.erase(i, 1);
            --i;
        }
    }
    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Filtered unsupported characters.\n";
    // }
}
