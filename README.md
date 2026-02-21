# Overview

This is a C++ 23 header-only library called `codex`. All functionality is sorted into what I have decided to call them "
Chapters." Each chapter is directed to focus on their area, e.g. `str.hpp` is focusing on string manipulations. As of
now, there is only the chapter str, which is a helper for common string
operations. All code is tested with the Google Test framework. The main philosophy is that the return value
could either be the actual value expected or an error code for failure using the `expected` class from the `expected`
header. The library is designed to be straightforward to use and understand, with clear and concise documentation for
each function. No dependencies are required. No exceptions are thrown.

## Table of Contents

- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Installation

### Option 1: Copy headers
Copy the `include/` folder into your project and add it to your include paths.

### Option 2: CMake (recommended)
Add `codex` as a subdirectory or via your preferred dependency manager, then include headers from `include/`.

## Usage
Let's say you want to use the string chapter. Then you would include the header file `str.hpp` and use the functions from there.
The header file is self-contained, and if you would like to trim a string, you would use the function `trim`.
Example:
```cpp '
#include <codex/str.hpp>

int main() { 
std::string s = " HeLLo ";
// Functions like trim return a new string (they do not mutate the input).
std::cout << codex::str::trim(s) << "\n";

// Functions that can fail return std::expected.
if (auto lowered = codex::str::to_lower(s); lowered.has_value()) {
std::cout << lowered.value() << "\n";
} else {
std::cout << "to_lower failed with StatusCode=" << static_cast<int>(lowered.error()) << "\n";
}
````



