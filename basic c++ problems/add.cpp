#include <iostream>
using namespace std;
int main()
{
	cout << "Hello World\n";
	int a = 5, b = 10, c;
	float e = 9.4;
	c = a + b;
	int d = a + e;
	cout << "c : " << c << endl;
	cout << "d : " << d << endl;
	cout << "d : " << typeid(d).name()<< endl;
	// cout << "addition : " <<type(a+e) << endl;
	cout << "e : " << (int)e / 2 << endl; // int always takes floor value
	printf("e : %.4f\n", e);
	cout << "sizeof(long) : " << sizeof(long);
	return 0;
}