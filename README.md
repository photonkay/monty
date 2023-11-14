# Monty Language Interpreter

## Overview

Monty is a simple programming language that operates on a stack or queue data structure. This project implements a Monty language interpreter in C, allowing users to write and execute Monty programs.

## Features

- **Stack and Queue Operations:** Supports stack (LIFO) and queue (FIFO) operations.
- **Arithmetic Operations:** Basic arithmetic operations such as addition, subtraction, multiplication, and division.
- **File Input:** Monty programs are written in files and executed through the interpreter.
- **Error Handling:** Provides informative error messages for syntax and runtime errors.

## Getting Started

### Prerequisites

- Ensure you have a C compiler installed (e.g., GCC).

### Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### Usage

```bash
./monty file.m
```

Replace `file.m` with the path to your Monty program file.

## Monty Language Syntax

A Monty program is a series of commands, with one command per line. Example:

```monty
push 1
push 2
push 3
pall
add
pall
```

This program pushes three values onto the stack, prints the stack, adds the top two elements, and prints the stack again.

## Commands

- `push <int>`: Pushes an integer onto the stack.
- `pop`: Removes the top element of the stack.
- `pall`: Prints all elements in the stack.
- `pint`: Prints element at the top of the stack.



## Contributors
Prince Odoi Asare - photonkay
Emekowa Deborah - techiedebzz
