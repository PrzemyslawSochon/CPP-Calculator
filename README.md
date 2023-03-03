# Calculator with a story

## Synopsis
This project taught me how unrealistic expectations I had about learning C++. Something that looks fairly simple took me months to pull off with major throw backs. While, I really enjoyed studying C++ itself, the integration of tools and technologies surrounding it proved me a great challenge.
Despite this repo being strictly reserved for a job recruitment purposes, I've decided to leave this note just to see how may I reflect upon this lovely origin story in the future.

## Requirements

Operating system:
MS Windows,
MacOS,
Linux (Debian-based or Arch-based)

## Installation

Before, proceeding, please see ## Requirements.

## Download

path/to/binary

## Features

### Build
You can build the project either with C++2017 or C++2020 standard. I have no plans of supporting other versions in the near future.
Usage: cmake -DCPP_VERSION_TEST_CXX_STANDARD="version number" <path/to/source>

Allowed values are following string literals: 17, 20, 23, 2017, 2020, 2023
Setting version to 2023 will set the CMake to build it with 2020 version, for compatibility sake.

To build project use CMake and build system of your choice.
You can also run tested scripts/fresh-build.sh to make sure everything goes smooth.

### Application
Prompts

You get nice verbose outputs to shell about what exact tasks calculator is performing and how it handles every equation step by step. To turn them off, open Settings in GUI. (But don't do that, I put them there for a reason).

Standardization of equations

You might expect that something fundamental as mathematics, after thousands of years of existence, would have developed into universal language with uniform symbols ant their interpretation. While it's true to some extent, I found awfully lot of irregularities in plain tasks. For example, does `^` mean exponentiation or XOR bitwise operation? Should we treat dash as minus, or is it separate symbol? How about periods and commas? And brackets? Should parenthesis be only allowed to dictate the order of operations or do we want live in friendly, inclusive math world when you can throw braces and chevrons as well?
I'm not sure, so I'm leaving it up to you, my dear user, with sleek menu instructing calculator how should it behave. (You can't actually throw bitwise operation in the middle of arithmetic equation, it's nonsense.)

Solution

You can pick how equation should be solved. There's postfix notation style solution (soon) or my twisted approach that walks you step by step explaining how the equation was solved (sooner).

### Development
Contribution

As you might've noticed I'm still learning, so you're welcome to contribute and suggest commits.

Platform

Project was developed using on the Arch Linux

Clang
CMake
ninja
VS Code