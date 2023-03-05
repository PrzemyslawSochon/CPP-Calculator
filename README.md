# Calculator with a story
---
<a href="calculator screenshot"><img src="https://raw.githubusercontent.com/PrzemyslawSochon/CPP-Calculator/507d87622c1e3c90184ee33064c58eb24e08ad17/CALCULATOR.png" align="middle"></a>
---
> ## Table of Contents

* [Synopsis](#Synopsis)
* [Requirements](#Requirements)
* [Build](#Build)
  * [Installation](#Installation)
  * [Tests](#Tests)
* [Download](#Downloads)
* [Features](#Features)
    * [Prompts](#Prompts)
    * [Standardization](#Standardization)
    * [Solution](#Solution)
* [Development](#Development)
  * [Contribution](#Contribution)
  * [Platform](#Platform)
* [About](#About)
  * [Contact](#Contact)
  * [Credits](#Credits)
* [License](#License)

---


## Synopsis
This project taught me how unrealistic expectations I had about learning C++. Something that looks quite simple caused me much trouble. Overall, I enjoyed studying C++ itself. The integration of tools and technologies surrounding it proved me a challenge.
Despite the fact that this repo was made for a job recruitment purposes, I've decided to leave this note to see how I may reflect upon this lovely origin story in the future.

## Requirements

Operating system:
Linux (Debian-based or Arch-based)

## Build
To build project use CMake and a build system of your choice.  
You can also run tested script inside <code>scripts/debug-build-run.sh</code>

The default variant of the build is Release. You can run Debug release by changing variable in the top CMakeLists.txt `CMAKE_BUILD_TYPE` to Debug  
or by running CMake command with <code>-DCMAKE_BUILD_TYPE=Debug</code> argument.  
  
Debug variant will considerably slow down build process, by running clang-tidy!

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

By default, you get nice verbose outputs to shell describing what calculator is doing at the moment.  
To turn them off, open Settings in GUI. (But don't do that, I put them there for a reason).

### Standardization


After thousands of years, you might expect that something fundamental as mathematics, would have developed into a universal language with uniform symbols and their interpretation. While it's true to some extent, I found a lot of irregularities in straightforward tasks. For example, does `^` mean exponentiation or XOR bitwise operation? Should we treat a dash as a minus, or is it a separate symbol? How about periods and commas? And brackets? Should only parenthesis be allowed to dictate the order of operations, or do we want to live in a friendly, inclusive math world where you can throw braces and chevrons as well?  
I don't know, so I'm leaving the choice to you, my dear user. With a sleek menu, you can choose how the calculator should perform some of its tasks.  
(You can't actually throw bitwise operation in the middle of arithmetic equation, it's nonsense.)

### Solution

(Soon™)

## Development

### Contribution

I'm a total beginner. Feel free to leave feedback and request pushes.

### Platform

The project was developed on the Arch Linux.  
I work with and really recommend the following:

* <a href="https://archlinux.org/packages/extra/x86_64/clang/">Clang LLVM compiler</a>
* <a href="https://archlinux.org/packages/extra/x86_64/cmake/">CMake software for build automation</a>
* <a href="https://archlinux.org/packages/community/x86_64/ninja/">Ninja build tools</a>
* <a href="https://archlinux.org/groups/x86_64/qt/">Qt Framework</a>

## About

### Contact

I'm actively looking for a job: przemyslaw.sochon@gmail.com

### Credits

My wallpaper: Forum Romanum, Rome, Italy. Photo by <a href="https://unsplash.com/@alyspara">Faith Crabtree</a> on <a href="https://unsplash.com/license">Unsplash</a>  
Terminal emulator: <a href="https://github.com/alacritty/alacritty">Alacritty</a>

## License

<a href="https://github.com/PrzemyslawSochon/CPP-Calculator/blob/main/LICENSE">MIT License</a>