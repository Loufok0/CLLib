# CLLib

## Description

This is a personnal project about building my own command line interface library in c++

---

## Instructions

### Prerequisites

- `make`
- `c++ 11`

### Setup

1. Clone the repository:

```bash
git clone https://github.com/Loufok0/CLLi.git
cd CLLib
```

2. Build th library:

```bash
make
```

3. Use it in your code and include it in your compilation as below:
```bash
c++ main.cpp CLLib.a
```

### Makefile Targets
| Target | Description |
|--------|-------------|
| `make` | Create the library archive compiled with `-Wall -Wextra -Werror` |
| `make clean` | Remove all the objects (files.o) |
| `make fclean` | `clean` + remove archive |
| `make re` | `fclean` + rebuild |
---

## Overview

The CLLib project is a lightweight and efficient command line interface library designed to serve programms with a cli following their needs, simple of usage. The primary goals of the project include:

- **Performance:** Optimized for speed, ensuring quick load times for users.
- **Simplicity:** A straightforward c++ cli class, Simplicity to add commands and description to them as needed.
- **Flexibility:** As using functions pointers, it's capable of a deep personnalisation of commands to meet different operational needs.

### Key Features:
- Adding multiple commands
- Adding descriptions to them for the help page
- Clean way to quit the cli
- Handle signals

### Language Composition

The core class logic is implemented in C++11.

## Screenshots
<img src="https://github.com/Loufok0/CLLib/blob/main/ressources/Show.png" width="800">

AI was not used to write this project — all configuration decisions were made and validated manually.


