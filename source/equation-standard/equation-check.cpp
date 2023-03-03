#include "../shared.hpp"
#include "equation.hpp"

#include <queue>


bool areBracketsOK(std::string_view str)
{
    std::queue<char> bracketQueue;
    for (const char &ch : str)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            bracketQueue.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (bracketQueue.empty())
            {
                return false;
            }
            char lastBracket = bracketQueue.front();
            bracketQueue.pop();
            if ((ch == ')' && lastBracket != '(') ||
                (ch == '}' && lastBracket != '{') ||
                (ch == ']' && lastBracket != '['))
            {
                return false;
            }
        }
    }
    return bracketQueue.empty();
}

bool areOuterOperatorsLegal(std::string_view str)
{
    if (isEFRMD(str[0]))
    {
        std::cout << "Illegal operator at the beginning of the expression!\n";
        return false;
    }
    if (isERMDAS(str.back()))
    {
        std::cout << "Illegal operator at the end of the expression!\n";
        return false;
    }
    for (std::size_t i{0}; i < str.size() - 1; ++i)
    {
        if ((str[i] == ')' && isERMDAS(str[i - 1])) || (str[i] == '(' && isEFRMD(str[i + 1])))
        {
            std::cout << "Illegal operator next to parenthesis!\n";
            return false;
        }
    }
    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Handled adjacent operators\n";
    // }
    return true;
}

bool areOperatorsLegal(std::string_view str)
{
    std::string_view illegal_pairs = "^^ %^ ^% ^/ /^ /% // %% ..";

    for (std::size_t i{0}; i < str.size() - 1; ++i)
    {
        if (illegal_pairs.find(str.substr(i, 2)) != std::string::npos)
        {
            std::cout << str;
            printCaretUnderIssue(i, i);
            std::cout << "Illegal expression!";
            return false;
        }
    }

    // if (g_verbose_terminal_prompts)
    // {
    //     std::cout << "Handled illegal expressions.\n";
    // }
    return true;
}

bool areCharsSupported(std::string_view str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (!doesCharMatchPattern(str[i], supportedCharactersArray))
        {
            std::cout << str;
            printCaretUnderIssue(i, i);
            std::cout << "Found unsupported character.\n";
            return false;
        }
    }
    return true;
}

bool hasRedundantSigns(std::string_view str)
{
    if (str[0] == '+')
    {
        return true;
    }

    std::vector<std::pair<char, char>> redundantSignPairs = {
        {'-', '-'},
        {'-', '+'},
        {'+', '+'},
        {'+', '-'},
        {'(', '+'},
        {'^', '+'},
        {'*', '+'},
        {'/', '+'},
    };

    for (std::size_t i{0}; i < str.size() - 1; ++i)
    {
        auto it = std::find_if(redundantSignPairs.begin(), redundantSignPairs.end(),
                               [str, i](const auto &sign)
                               { return sign == std::make_pair(str[i], str[i + 1]); });

        if (it != redundantSignPairs.end())
        {
            return true;
        }
    }
    return false;
}

bool hasNumberNextToBracket(std::string_view str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (str[i] == '(' && i > 0 && isAlphanumeric(str[i - 1]))
        {
            std::cout << str;
            printCaretUnderIssue(i, i);
            std::cout << "Adjacent number to bracket.\n";
            return true;
        }

        else if (str[i] == ')' && i < str.size() - 1 && isAlphanumeric(str[i + 1]))
        {
            std::cout << str;
            printCaretUnderIssue(i, i);
            std::cout << "Adjacent number to bracket.\n";
            return true;
        }
    }

    return false;
}

bool hasDoubleAsterisks(std::string_view str)
{
    for (std::size_t i{0}; i < str.size() - 1; ++i)
    {
        if (str[i] == '*' && str[i + 1] == '*')
        {
            return true;
        }
    }
    return false;
}

bool hasCommas(std::string_view str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (str[i] == ',')
        {
            return true;
        }
    }
    return false;
}

bool hasInvalidBrackets(std::string_view str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == ']' || str[i] == '}')
        {
            return true;
        }
    }
    return false;
}

bool hasBackslashes(std::string_view str)
{
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (str[i] == '\\')
        {
            return true;
        }
    }
    return false;
}

bool hasPercentSign(std::string_view str)
{
    for (const char &ch : str)
    {
        if (ch == '%')
        {
            return true;
        }
    }
    return false;
}

bool doesUserInputNeedAutoRepair(std::string_view str)
{
    return (
        hasNumberNextToBracket(str) ||
        hasRedundantSigns(str) ||
        hasDoubleAsterisks(str) ||
        hasCommas(str) ||
        hasInvalidBrackets(str) ||
        hasBackslashes(str));
}

bool isUserInputBrokenBeyondAutoRepair(std::string_view str)
{
    return !(
        areCharsSupported(str) &&
        areBracketsOK(str) &&
        areOuterOperatorsLegal(str) &&
        areOperatorsLegal(str));
}