This is an attempt to write a wrapper mimicking borland's graphics.h on top of SFML.

# Directory Structure

- **graphix.h:** Contains function prototypes and enums.
- **graphix.cpp:** Includes the function definitions.

## Compilation

Use `make` to compile the project using the provided Makefile.

## Dependencies

- **SFML**
https://www.sfml-dev.org

## Implemented Functions
- initgraph
- putpixel
- closegraph

## Updates
It works and now you can write and run code involving putpixel in main.cpp. But it sometimes segfaults when exiting 
the program/closing the window due to something to do with SFML and its non-thread safety. Worst part is that it 
never crashes when I'm running it through gdb.

I'm way too sleepy to care right now. Point is you can write graphics.h code involving putpixel now and it should run fine
with the occasional seg fault occuring when the program execution stops.
