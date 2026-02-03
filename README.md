## HW0 / Lab 3 – Systems Programming (GitHub Codespaces)

This repository contains my work for HW0 and Lab 3, completed using **GitHub Codespaces** on an Ubuntu Linux environment. The purpose of this assignment is to gain hands-on experience with systems programming tools and concepts such as `make`, `gdb`, `objdump`, Linux resource limits, and basic C programming.

---

## Environment

- Platform: GitHub Codespaces (Ubuntu Linux)
- Compiler: gcc
- Debugger: gdb
- Build Tool: make
- Other Tools: objdump, tmux, vim/nano

All required tools were available in the provided Codespace environment.

---

## Project Structure

project1/
├── Makefile
├── wc.c
├── main.c
├── map.c
├── gdb.txt
├── objdump.txt
├── map.txt
└── README.md

---

## Building the Programs

To compile the programs, run:

```bash
make
To remove compiled files:

make clean
wc – Word Count Clone

The wc program is a simplified clone of the Linux wc utility.

Supported Usage
./wc FILE_NAME
./wc


Counts the number of lines, words, and characters

Reads from standard input if no file is provided

Behavior matches Ubuntu wc (flags not required)

Example
./wc wc.c
echo "hello world" | ./wc

gdb Analysis

The wc executable was analyzed using gdb by:

Setting a breakpoint at main

Stepping through execution

Inspecting argv, stack frames, and registers

Viewing the call stack with bt

Answers and explanations are recorded in gdb.txt.

objdump Analysis

The executable was inspected using:

objdump -x -d wc


This analysis was used to:

Identify the executable file format and architecture

Locate the main function in the .text section

Examine sections such as .text, .data, .bss, and .rodata

Understand why stack and heap do not appear as executable sections

Answers are recorded in objdump.txt.

Bonus: map – Memory Layout

The map program prints addresses from different memory regions at runtime:

Function addresses

Stack addresses (including recursive calls)

Static data addresses

Heap allocations

These addresses were compared with objdump -D map output to determine which are defined in the executable and which exist only at runtime.

Analysis is recorded in map.txt.

User Resource Limits

main.c was modified to use getrlimit() to print the soft limits for:

Stack size (RLIMIT_STACK)

Maximum number of processes (RLIMIT_NPROC)

Maximum number of file descriptors (RLIMIT_NOFILE)

Example output:

stack size: 8388608
process limit: 2782
max file descriptors: 1024
