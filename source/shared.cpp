#include "shared.hpp"

void removeTrailingZeros(std::string &str)
{
    std::replace(str.begin(), str.end(), ',', '.');
    std::size_t decimal_position = str.find('.');
    if (decimal_position == std::string::npos)
    {
        return;
    }

    std::size_t last_nonzero = str.find_last_not_of('0');
    if (last_nonzero == decimal_position)
    {
        str.erase(decimal_position);
        return;
    }

    str.erase(last_nonzero + 1);
}

void printCaretUnderIssue(const std::size_t &i1, const std::size_t &i2)
{
    std::size_t num_spaces{i1};
    std::size_t num_carets{i2 - i1 + 1};

    std::string output(num_spaces, ' ');
    output += std::string(num_carets, '^');

    std::cout << '\n'
              << output << '\n';
}
