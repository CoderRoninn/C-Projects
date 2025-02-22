⚙️ DOGUKAN'S CALCULATOR ⚙️

⭐ INTRODUCTION ⭐

Welcome to DOGUKAN'S CALCULATOR!
This is a powerful, user-friendly calculator built in C that handles basic arithmetic, trigonometric, logarithmic, and advanced mathematical functions. The design focuses on ease of use, efficiency, and flexibility, making it a great tool for students, professionals, or anyone who needs quick and reliable calculations.

This calculator handles multiple mathematical operations, includes error handling, and ensures a smooth user experience with an interactive menu system.

✒️ FEATURES ✒️

1. Basic Arithmetic Operations:

Addition: Adds two numbers.
Subtraction: Subtracts one number from another.
Multiplication: Multiplies two numbers.
Division: Divides one number by another (includes checks for division by zero).

2. Advanced Mathematical Functions:

Exponentiation (Power): Calculate a^b (a raised to the power of b).
Square Root: Calculates the square root of a non-negative number.
Factorial: Computes the factorial of an integer (n!).
Logarithm: Computes the natural logarithm (log(x)), as well as logarithms to other bases (optional).
Modulo Operation: Computes the remainder of a division operation (a % b).

3. Trigonometric Functions:

Sine (sin): Computes the sine of an angle.
Cosine (cos): Computes the cosine of an angle.
Tangent (tan): Computes the tangent of an angle.
Cotangent (cot): Computes the cotangent of an angle.
Secant (sec): Computes the secant of an angle.
Cosecant (csc): Computes the cosecant of an angle.
Note: All trigonometric functions use degrees as input for angles. Radians are supported upon request by modification.

4. User-Friendly Interface:
A simple, intuitive text-based menu system.
Clear prompts and messages guide the user throughout the operation.
Easily navigate between operations with a prompt-driven interface.

5. Error Handling:
Zero Division Prevention: The program gracefully handles division by zero with an error message.
Negative Square Root Handling: If the user attempts to calculate the square root of a negative number, an error message will be displayed.
Invalid Inputs: The program verifies numeric input and ensures that the user enters valid data for each operation.

6. Memory Management:
Uses dynamic memory allocation to efficiently store input values and results.
Proper memory deallocation after each operation to avoid memory leaks.

7. Advanced Features:
Recursive Functions: Supports recursive calculation for operations like factorial.
Multiple Calculations: Perform multiple operations sequentially without restarting the program.
Clear Instructions: Step-by-step guidance for entering data and interpreting results.

🔧 HOW TO USE 🔧

Step-by-Step Guide:

Start the Program:
After running the program, you will see the main menu. Choose an operation by entering the corresponding number.

Select Operation:
The program supports various operations. Enter the number of the desired operation (e.g., 1 for addition, 2 for subtraction, etc.).

Enter Values:
For basic operations, you will be prompted to input two numbers (e.g., 5 and 3 for 5 + 3).
For advanced functions (like square root or factorial), you will only need to enter one value.
For trigonometric functions, enter the angle in degrees.

Perform Calculation:
After entering the necessary values, the program will perform the calculation and display the result.
You can continue performing operations using the result of the previous calculation or restart with new values.

Repeat Operations:
You can repeat the calculation with new numbers or results from previous operations.
The program will return to the main menu for each new operation.

Exit the Program:
When you're done, select the Exit option from the main menu. The program will safely exit and free any dynamically allocated memory.

⚙️ SYSTEM REQUIREMENTS ⚙️

A C compiler (e.g., GCC, MinGW, or any other compatible compiler).
The standard C library (stdio.h, stdlib.h, math.h).

Installation Instructions:
Clone or download the repository to your local machine.
Open the terminal and navigate to the folder containing the calculator.c file.
Compile the program with gcc calculator.c -o calculator -lm to link the math library (-lm).
Run the program by executing ./calculator.

⚠️ ERROR HANDLING ⚠️
The calculator includes the following error handling features:

Division by Zero:
If you try to divide by zero, the program will alert you with an error message:
"Error: Division by zero is not allowed!".

Negative Square Root:
If you attempt to compute the square root of a negative number, the program will display an error:
"Error: Cannot calculate the square root of a negative number!".

Invalid Input:
If you enter a non-numeric value when a number is expected, the program will ask you to enter a valid number again.

Out-of-Range Trigonometric Inputs:
For trigonometric calculations, the program checks for valid angle inputs. For example, if the input is out of range for a function (e.g., tan(90°)), it will show a warning:
"Warning: Undefined value for tan(90°). Please choose a different angle.".

🧮 EXAMPLES 🧮
Example 1: Basic Arithmetic
Operation: Addition
Input: 5 + 3
Output: 8
Example 2: Trigonometric Calculation
Operation: Sine
Input: sin(30°)
Output: 0.5
Example 3: Advanced Function (Factorial)
Operation: Factorial
Input: 5!
Output: 120
Example 4: Exponential Calculation
Operation: Power
Input: 2^3
Output: 8

🛠️ CONTACT 🛠️
For further queries, suggestions, or issues, feel free to open an issue in the repository or contact me at [dogubey2112@gmail.com].