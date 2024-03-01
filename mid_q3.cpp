#include <simplecpp>
#include <string>

double performOp(double num1, double num2, char operation) {
    double result = 0.0;
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                throw runtime_error("Sorry, Division by zero is not allowed.");
            }
            break;
        default:
            throw runtime_error("This operation is Invalid.");
    }
    return result;
}

main_program {
    double num1, num2;
    char operation;

    cout << "Enter the first number: ";
    if (!(cin >> num1)) {
        cout << "Invalid input for the first number." <<endl;
        return 1;
    }

    cout << "Please enter the operation (+, -, *, /): ";
    cin >> operation;

    cout << "Please enter the second number: ";
    if (!(cin >> num2)) {
        cout << "Invalid input for the second number." << endl;
        return 1;
    }

    try {
        double result = performOp(num1, num2, operation);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}