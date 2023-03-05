# Calculator with a story
---
<a href="calculator screenshot"><img src="https://raw.githubusercontent.com/PrzemyslawSochon/CPP-Calculator/507d87622c1e3c90184ee33064c58eb24e08ad17/CALCULATOR.png" align="middle"></a>
---
> ## Table of Contents

* [Synopsis](#Synopsis)
* [Requirements](#Requirements)
* [Installation](#Structure-of-a-readme)
* [Tests](#Tests)
* [Download](#Downloads)
* [Features](#Features)
  * [Build](#Build)
  * [Application](#Application)
      * Prompts
      * Standardization
      * Solution
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

## Installation

(Soon™)

## Tests

(Sooner™)

## Download

<a href="https://github.com/PrzemyslawSochon/CPP-Calculator/raw/main/binary/Calculator">Download compiled binary file</a>

## Features

### Build
You can build the project either with C++2017 or C++2020 standard. I have no plans of supporting other versions in the near future.
Usage: <code>cmake [-DCPP_VERSION_TEST_CXX_STANDARD="version_number"] [<path/to/source>]</code>  
["version_number"] allowed values: <code>17, 20, 23, 2017, 2020, 2023</code>
Setting version to 2023 will successfully run the project, but with 2020 standard.  

If you're not familiar with the commands above, you can refer to <code>/scripts</code> directory.  
Make sure you've CMake and compatible build system beforehand.

### Application
<b>Prompts</b>

By default, you get nice verbose outputs to shell describing what calculator is doing at the moment.  
To turn them off, open Settings in GUI. (But don't do that, I put them there for a reason).

<b>Standardization</b>

After thousands of years, you might expect that something fundamental as mathematics, would have developed into a universal language with uniform symbols and their interpretation. While it's true to some extent, I found a lot of irregularities in straightforward tasks. For example, does `^` mean exponentiation or XOR bitwise operation? Should we treat a dash as a minus, or is it a separate symbol? How about periods and commas? And brackets? Should only parenthesis be allowed to dictate the order of operations, or do we want to live in a friendly, inclusive math world where you can throw braces and chevrons as well?  
I don't know, so I'm leaving the choice to you, my dear user. With a sleek menu, you can choose how the calculator should perform some of its tasks.  
(You can't actually throw bitwise operation in the middle of arithmetic equation, it's nonsense.)

<b>Solution</b>

(Soon™)

## Development

### Contribution

As you might've noticed I'm still learning. You're welcome to request pushes and share feedback.

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