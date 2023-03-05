# Calculator with a story
---
<a href="calculator screenshot"><img src="https://raw.githubusercontent.com/PrzemyslawSochon/CPP-Calculator/507d87622c1e3c90184ee33064c58eb24e08ad17/CALCULATOR.png" align="middle"></a>
---
> ## Table of Contents

* [Synopsis](#Synopsis)
* [Requirements](#Requirements)
* [Build](#Build)
  * [Installation](#Structure-of-a-readme)
  * [Tests](#Tests)
* [Download](#Downloads)
* [Features](#Features)
      * Prompts
      * Standardization
      * Solution
* [Development](#Development)
  * [Contribution](#Contribution)
  * [Platform](#Platform) 
* [About](#About)

---


## Synopsis
This project taught me how unrealistic expectations I had about learning C++. Something that looks fairly simple caused me much trouble. While, I really enjoyed studying C++ itself, the integration of tools and technologies surrounding it proved me a great challenge.
Despite this repo being reserved for a job recruitment purposes, I've decided to leave this note just to see how may I reflect upon this lovely origin story in the future.

## Requirements

Operating system:
Linux (Debian-based or Arch-based)

## Build
To build project use CMake and a build system of your choice.  
You can also run tested script inside <code>scripts/debug-build-run.sh</code>

The default variant of the build is Release. You can run Debug release by changing variable in the top CMakeLists.txt `CMAKE_BUILD_TYPE` to Debug  
or by running CMake command with <code>-DCMAKE_BUILD_TYPE=Debug</code> argument.

The default C++ standard is set to 2020. You can build the project either with that or 2017 standard. I have no plans of supporting other versions in the near future.  
Analogically, to change language standard tweak <code>CPP_VERSION_TEST_CXX_STANDARD</code>

### Installation

The installation takes about 2MB of storage. If successful, you can find it inside <code>/usr/local/bin/</code>  
To install the program, run installation script from <code>/scripts/installation.sh</code>

### Tests

(Soon™)

## Download

(Sooner™)

## Features

### Prompts

You get nice verbose outputs to shell about what tasks calculator is performing and how it handles every equation step by step. To turn them off, open Settings in GUI. (But don't do that, I put them there for a reason).

### Standardization

You might expect that something fundamental as mathematics, after thousands of years of existence, would have developed into universal language with uniform symbols ant their interpretation. While it's true to some extent, I found awfully lot of irregularities in plain tasks. For example, does `^` mean exponentiation or XOR bitwise operation? Should we treat dash as minus, or is it separate symbol? How about periods and commas? And brackets? Should parenthesis be only allowed to dictate the order of operations or do we want live in friendly, inclusive math world when you can throw braces and chevrons as well?
I'm not sure, so I'm leaving it up to you, my dear user, with sleek menu instructing calculator how should it behave. (You can't actually throw bitwise operation in the middle of arithmetic equation, it's nonsense.)

### Solution

(Soon™)

## Development

### Contribution

As you might've noticed I'm still learning. You're welcome to request pushes and share feedback.

### Platform

Project was developed on the Arch Linux, using the following:

GNU GCC
Clang LLVM
CMake
ninja build
VS Code
Qt Creator

## About

(Soon™)