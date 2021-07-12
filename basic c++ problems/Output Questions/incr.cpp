#include <iostream>
using namespace std;
int main()
{
	int a=4, b=5;
	b = a++ + a--;
	a = ++b + b--;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	return 0;
}