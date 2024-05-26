# Project Algorithm Design

## Prerequisites

To run this project, you need to be on a Linux distribution.

### For Debian-based Distributions

Install the following packages:

- **Valgrind**: A programming tool for memory debugging, memory leak detection, and profiling.
- **GCC**: The GNU Compiler Collection, a compiler system produced by the GNU Project.
- **Make**: A build automation tool that automatically builds executable programs and libraries from source code.
- **Python**: A high-level, interpreted programming language.
- **LaTeX**: A document preparation system used for the communication and publication of scientific documents.

Use the following commands to install these packages:

sudo apt update
sudo apt install valgrind gcc make python3 texlive-full

### For Arch-based distributions, install the equivalent packages using the following commands:

sudo pacman -Syu
sudo pacman -S valgrind gcc make python texlive-core

## Building and running

To compile the C implementation, run "make" while in the project directory.
To run the C implementation, run "make run target=name-of-file"
To debug using Valgrind, use "make debug target=name-of.file"

To run the python implementaion, run "python main.py name-of-file" in the src_py directory.

