#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x = 2.3, y = 0.25;
	int z = -10;
	cout << "sin(x) : " << sin(x) << endl;
	cout << "cos(x) : " << cos(x) << endl;
	cout << "tan(x) : " << tan(x) << endl;
	cout << "sqrt(y) : " << sqrt(y) << endl;
	cout << "abs(z) : " << abs(z) << endl; 			 // prints positive value
	cout << "round(x)) : " << round(x) << endl;
	cout << "pow(2.3,0.25) : " << pow(x, y) << endl; // pow(number,power)
	x = 3, y = 4;									 // reinitialise
	cout << "hypotenuse : " << hypot(x, y) << endl;
	x = 4.57;
	cout << "floor(x) : " << floor(x) << endl;
	cout << "ceil(x) : " << ceil(x) << endl;
	x = -4.57;
	cout << "fabs(x) : " << fabs(x) << endl;
	x = 1.0;
	// arc values (arc sine is the inverse operation of sine)
	cout << "sin(x) : " << sin(x) << endl;
	cout << "asin(x) : " << asin(x) << endl;
	cout << "acos(x) : " << acos(x) << endl;
	cout << "atan(x) : " << atan(x) << endl;
	x = 57.3;
	// hyperbolic
	cout << "sinh(x) : " << sinh(x) << endl;
	cout << "cosh(x) : " << cosh(x) << endl;
	cout << "tanh(x) : " << tanh(x) << endl;
	y = 100.0;
	cout << "log(y) : " << log(y) << endl;
}