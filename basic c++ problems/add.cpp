#include <iostream>
#include <typeinfo> // for typeid()
using namespace std;
int main()
{
	cout << "Hello World\n";
	int a = 5, b = 10, c;
	float e = 9.4;
	float f;
	c = a + b;
	int d = a + e;
	f = a + e;
	cout << "c : " << c << endl;
	cout << "d : " << d << endl;
	cout << "d : " << typeid(e).name() << endl; // find data type while runtime
	cout << "addition : " <<typeid(a+e).name() << endl;
	cout << "(int)e / 2 : " << (int)e / 2 << endl; // int always takes floor value
	printf("e : %.4f\n", e);
	cout << "sizeof(long) : " << sizeof(long);
	return 0;
}

// always the data type with higher precedence in a expression ends as resultant data type
// char < int < float < double