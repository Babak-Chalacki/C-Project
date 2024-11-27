#include <iostream>
#include <cmath>

using namespace std;

long long factorial(int n) {
    if (n < 0) return -1;
    if (n == 0) return 1;
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int choice;
    double number, angle;

    cout << "Simple Calculator\n";
    cout << "1. Square Root (sqrt)\n";
    cout << "2. Sine (sin)\n";
    cout << "3. Cosine (cos)\n";
    cout << "4. Tangent (tan)\n";
    cout << "5. Cotangent (cot)\n";
    cout << "6. Factorial\n";
    cout << "0. Exit\n";
    
    while (true) {
        cout << "Please choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> number;
                cout << "Square root of " << number << " = " << sqrt(number) << endl;
                break;

            case 2:
                cout << "Enter an angle (in degrees): ";
                cin >> angle;
                angle = angle * M_PI / 180.0;
                cout << "sin(" << angle * 180.0 / M_PI << ") = " << sin(angle) << endl;
                break;

            case 3:
                cout << "Enter an angle (in degrees): ";
                cin >> angle;
                angle = angle * M_PI / 180.0;
                cout << "cos(" << angle * 180.0 / M_PI << ") = " << cos(angle) << endl;
                break;

            case 4:
                cout << "Enter an angle (in degrees): ";
                cin >> angle;
                angle = angle * M_PI / 180.0;
                cout << "tan(" << angle * 180.0 / M_PI << ") = " << tan(angle) << endl;
                break;

            case 5:
                cout << "Enter an angle (in degrees): ";
                cin >> angle;
                angle = angle * M_PI / 180.0;
                if (tan(angle) != 0) {
                    cout << "cot(" << angle * 180.0 / M_PI << ") = " << 1/tan(angle) << endl;
                } else {
                    cout << "cot(" << angle * 180.0 / M_PI << ") is undefined." << endl;
                }
                break;

            case 6:
                int n;
                cout << "Enter a number: ";
                cin >> n;
                long long result = factorial(n);
                if (result == -1) {
                    cout << "Factorial is not defined for negative numbers." << endl;
                } else {
                    cout << n << "! = " << result << endl;
                }
                break;

            case 0:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        cout << endl;
    }

    return 0;
}