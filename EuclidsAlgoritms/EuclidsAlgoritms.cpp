// EuclidsAlgoritms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

struct ExtendedAlgorithmAnswer
{
	int a, b, gcd;
};

int calculateGCDEuclidAlgorithm(int, int);
ExtendedAlgorithmAnswer calculateGCDExtendedEuclidAlgorithm(int, int);

int main()
{
	int x1, x2;
	cout << "Enter x1: ";
	cin >> x1;
	cout << "Enter x2: ";
	cin >> x2;
	cout << endl;

	cout << "1 - Calculate GCD by Euclid algorithm;\n2 - Calculate GCD by extended Euclid algorithm;\n3 - Exit" << endl << endl;
	int choice = _getch();

	switch (choice) {
	case 49:
		cout << "Greatest common divisor (GCD) by Euclid algorithm: " << calculateGCDEuclidAlgorithm(x1, x2) << endl << endl;
		break;
	case 50:
		ExtendedAlgorithmAnswer answer = calculateGCDExtendedEuclidAlgorithm(x1, x2);
		cout << "Greatest common divisor (GCD) by extended Euclid algorithm: " << answer.gcd << endl;
		cout << "a: " << answer.a << endl;
		cout << "b: " << answer.b << endl << endl;
		break;
	default:
		break;
	}

	system("pause");
}

int calculateGCDEuclidAlgorithm(int x1, int x2) {
	int a = fmax((double)x1, (double)x2);
	int b = fmin((double)x1, (double)x2);

	int r = b;
	while (r != 0) {
		b = r;
		r = a % b;
		a = b;
	}

	return b;
}

ExtendedAlgorithmAnswer calculateGCDExtendedEuclidAlgorithm(int x1, int x2) {
	int m = fmax((double)x1, (double)x2);
	int n = fmin((double)x1, (double)x2);
	
	int a = 0;
	int a1 = 1;
	int c = m;
	int b = 1;
	int b1 = 0;
	int d = n;

	int q;
	int r;
	int t;
	while (true) {
		q = c / d;
		r = c % d;

		if (r != 0) {
			c = d;
			d = r;
			t = a1;
			a1 = a;
			a = t - q * a;
			t = b1;
			b1 = b;
			b = t - q * b;
		}
		else
		{
			break;
		}
	};

	return ExtendedAlgorithmAnswer{ a, b, a * m + b * n };
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
