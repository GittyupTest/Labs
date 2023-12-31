#include <iostream>

#include "Fraction.h"

int main()
{
	using std::cin;
	using std::cout;
	int n, d;
	cout << "Enter the first fraction: ";
	cin >> n >> d;
	while (d == 0) {
		cout << "Denominator can't be zero! Please enter a valid denominator: ";
		cin >> d;
	}
	Fraction a(n, d);

	cout << "Enter the second fraction: ";
	cin >> n >> d;
	while (d == 0) {
		cout << "Denominator can't be zero! Please enter a valid denominator: ";
		cin >> d;
	}
	Fraction b(n, d);

	if (a == b) { //a.operator==(b);
		std::cout << "Fractions is equal.\n";
	}
	else {
		std::cout << "Fractions is not equal.\n";
	}

	return 0;
}