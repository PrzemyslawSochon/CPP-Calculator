#pragma once

#include <iostream>
#include <span>

struct Foo;

consteval int sum(std::span<const int> a);

auto sum(auto x, auto y) -> decltype(x + y);