#include <iostream>
using namespace std;

// Function Prototypes
unsigned long long factorial(int num);
int fibNum(int a, int b, int n);

int main() {
	int factNum;
	int firstFib, secondFib, nth;

	cout << "Enter a number to which you want the factorial of: ";
	cin >> factNum;
	
	cout << "The factorial of " << factNum << "! is: " 
		<< factorial(factNum) << ".\n" << endl;
	
	cout << "Time to test the Fibonacci Number Calculator..." << endl;
	cout << "\nEnter the first Fibonacci Number: ";
	cin >> firstFib;

	cout << "\nNow enter the second Fibonacci Number: ";
	cin >> secondFib;

	cout << "\nNow enter the position of the desired " 
		<< "Fibonacci Number in the sequence: ";
	cin >> nth;

	cout << "\nThe Fibonacci Number at position " << nth
		<< " is: " << fibNum(firstFib, secondFib, nth) << endl;

	system("pause");
	return 0;
}

unsigned long long factorial(int num) {
	if (num == 0) {
		return 1;
	}
	else {
		return num * factorial(num - 1);
	}
}

int fibNum(int a, int b, int n) {

	if (n == 1) {
		return a;
	}
	else if (n == 2) {
		return b;
	}
	else {
		return fibNum(a, b, n - 1) + fibNum(a, b, n - 2);
	}
}
