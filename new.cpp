#include <iostream>

using namespace std;

int main()
{
    int n1, n2; // Variables to store two numbers
    char c;     // Variable to store the operator

    // Prompt the user to enter two numbers
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;




    

    // Prompt the user to enter an operator
    cout << "Enter an operator (+, -, *, /): ";
    cin >> c;

    // Perform the operation based on the operator entered
    switch (c)
    {
    case '+': // Addition case
        cout << n1 << " + " << n2 << " = " << n1 + n2;
        break;

    case '-': // Subtraction case
        cout << n1 << " - " << n2 << " = " << n1 - n2;
        break;

    case '*': // Multiplication case
        cout << n1 << " * " << n2 << " = " << n1 * n2;
        break;

    case '/': // Division case
        if (n2 != 0) // Check for division by zero
        {
            cout << n1 << " / " << n2 << " = " << n1 / n2;
        }
        else
        {
            cout << "Error: Division by zero";
        }
        break;

    case '%': // Modulus case (optional, only works for integers)
        if (n2 != 0) // Check for division by zero
        {
            cout << n1 << " % " << n2 << " = " << n1 % n2;
        }
        else
        {
            cout << "Error: Division by zero";
        }
        break;

    default: // Default case for invalid operator
        cout << "Error: Invalid operator";
        break;
    }

    return 0; // Indicate successful program termination
}