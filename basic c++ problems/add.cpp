#include <iostream>
using namespace std;
int main()
{
	cout << "Hello World\n";
	int a = 5, b = 10, c;
	float e = 9.4;
	c = a + b;
	cout << "c : " << c << endl;
	cout << "e : " << (int)e / 2 << endl; // int always takes floor value
	printf("e : %.4f\n", e);
	cout << "sizeof(long) : " << sizeof(long);
}