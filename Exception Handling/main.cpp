// Simple exception handling program
// shows how to use exception handling, example dividing by zero
#include <iostream>

using namespace std;

int main() {
	int dividend, divisor, quotient;

	try {
		cout << "Enter the dividend: ";
		cin >> dividend;
		cout << endl;

		cout << "Enter the divisor: ";
		cin >> divisor;
		cout << endl;

		if (divisor == 0) {
			throw 0;
		}

		quotient = dividend / divisor;

		cout << "Quotient = " << quotient << "." << endl;
	}
	catch (int) {
		cout << "Sorry, can't divide by zero!.\n";
	}

	system("pause");
	return 0;
}
