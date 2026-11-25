# C Preprocessor – mypreprocessor

## 1. Project Overview

mypreprocessor is a basic C preprocessor tool developed using the C programming language. It accepts a C source file, performs preprocessing operations and generates an output file with the `.i` extension.

## 2. Objectives

- Remove single-line and multi-line comments.
- Process user-defined header file inclusion.
- Perform object-like macro substitution.
- Perform basic function-like macro substitution.
- Generate a preprocessed output file.

## 3. Features

### Comment Removal
Removes:
- Single-line comments (`//`)
- Multi-line comments (`/* ... */`)

### File Inclusion
Processes user-defined header files and includes their contents in the output.

### Macro Substitution
Supports:
- Object-like macros, such as `#define PI 3.14`
- Basic single-argument function-like macros, such as `#define SQUARE(x) ((x)*(x))`

### Output Generation
Generates a preprocessed file with the `.i` extension.

## 4. Project Structure

| File | Description |
|---|---|
| main.c | Controls the preprocessing workflow |
| comment_removal.c | Implements comment removal |
| comment_removal.h | Comment removal declarations |
| macro_handler.c | Macro storage and substitution |
| macro_handler.h | Macro handler declarations |
| file_inclusion.c | Header file copying functionality |
| file_inclusion.h | File inclusion declarations |
| Makefile | Automates compilation |

## 5. Requirements

- GCC compiler
- Linux environment
- Make utility (for automated compilation)

## 6. Compilation

Run:

```bash
make
```

Alternatively, compile manually:

```bash
gcc main.c comment_removal.c macro_handler.c file_inclusion.c -o mypreprocessor
```

## 7. Execution

```bash
./mypreprocessor input.c
```

The generated output will be saved as:

```text
input.i
```

## 8. Testing

The project was tested with:
- Single-line and multi-line comments
- Object-like macros
- Single-argument function-like macros
- User-defined header files
- System header directives

The generated output was also compiled and executed using GCC.

## 9. Current Limitations

- Function-like macros support one argument.
- Recursive header inclusion is not implemented.
- System header directives are preserved rather than expanded by this tool.
- This project implements a basic subset of C preprocessing functionality.

## 10. Technologies Used

- C Programming Language
- File Handling
- String Handling
- Structures
- GCC Compiler
- Makefile
