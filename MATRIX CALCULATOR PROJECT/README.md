# Matrix Calculator

A command-line matrix calculator written in C. This program allows users to create dynamic matrices and perform a variety of single and multi-matrix mathematical operations.

## Features

**Single Matrix Operations**
* Trace
* Transpose
* Determinant (up to 3x3)
* Scalar Multiplication
* Row and Column Sum
* Matrix Power
* Symmetric and Skew-Symmetric Checks
* Identity Matrix Check

**Two Matrix Operations**
* Addition
* Subtraction
* Multiplication
* Equality Check

## File Structure

* `main.c`: Contains the user interface, menus, and input/output handling.
* `calculator.c`: Contains the core mathematical logic and function definitions.
* `calculator.h`: The header file containing function declarations.

## How to Run

**Using an IDE (Code::Blocks, VS Code, etc.):**
1. Ensure all three files (`main.c`, `calculator.c`, `calculator.h`) are added to the same project workspace or folder.
2. Build and run the project.

**Using the Terminal (GCC):**
1. Open your terminal in the project directory.
2. Compile the project by linking the C files:
   ```bash
   gcc main.c calculator.c -o matrix_calc
