#include "test-cpp20.hpp"

#include <array>

struct Foo
{
    int a{ };
    int b{ };
    int c{ };
};

consteval int sum(std::span<const int> a) // std::span and consteval
{
    int s{ 0 };
    for (auto n : a)
        s += n;
    return s;
}

auto sum(auto x, auto y) -> decltype(x + y) // abbreviated function templates
{
    return x + y;
}
