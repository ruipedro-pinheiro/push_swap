# Push_swap

## Description
Push_swap is a 42 school project that involves sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## Usage

### Compilation
Use `make` to compile the project.
```bash
make
```

### Execution
Run the program with a list of integers as arguments:
```bash
./push_swap 4 67 3 87 23
```
Or as a single string:
```bash
./push_swap "4 67 3 87 23"
```

## Features
- **Argument Parsing**: Handles integers, checks for non-numeric input, integer overflows/underflows, and duplicates.
- **Stack Management**: Dynamically allocates nodes for the stack.

## Structure
- `src/`: Source files.
- `include/`: Header files.
- `libft/`: Custom C library.

## Author
rpinheir
