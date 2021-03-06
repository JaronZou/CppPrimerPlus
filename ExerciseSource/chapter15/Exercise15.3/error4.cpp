// error4.cpp - using exception classes
#include <iostream>
#include <cmath>
#include "exc_mean.h"

// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	double x, y, z;

	cout << "Enter two numbers: ";
	while(cin >> x >> y) {
		try {					// start of try block
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			cout << "Gemoteric mean of " << x << " and " << y
				<< " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}	// end of try block
		catch (bad_hmean & bh) {// start of catch block
			bh.mesg();
			break;
		}
		catch (bad_gmean & bg) {
			bg.mesg();
			break;
		}
	}
	cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b) {
	if (a == -b)
		throw bad_hmean(a, b, "hmean()");
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
	if (a < 0 || b < 0)
		throw bad_gmean(a, b, "gmean()");
	return std::sqrt(a * b);
}