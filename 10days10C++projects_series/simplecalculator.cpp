#include <iostream>

using namespace std;

int main() {
    char operation;
    double num1, num2;
    bool keepRunning = true;

    cout << "Welcome to the Simple Calculator!" << endl;

    do {
        cout << "\nEnter an operation (+, -, *, /) or 'q' to quit: ";
        cin >> operation;

        if (operation == 'q') {
            keepRunning = false;
            cout << "Exiting the calculator. Goodbye!" << endl;
            break;
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (operation) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid operation. Please try again." << endl;
        }
    } while (keepRunning);

    return 0;
}


