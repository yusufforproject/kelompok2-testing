#include <iostream>
using namespace std;

int main() {
    double num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    double sum = num1 + num2;
    double difference = num1 - num2;
    double product = num1 * num2;

    // Add division by zero check
    double quotient;
    if (num2 != 0) {
        quotient = num1 / num2;
    } else {
        cout << "Error: Division by zero is not allowed." << endl;
        return 1; // Exit with an error code
    }

    cout << "\nResults:" << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;

    return 0;
}
