#pragma once

#include <tuple>
#include <type_traits>

template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args);
