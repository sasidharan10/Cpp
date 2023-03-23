#include <iostream>
using namespace std;
int main()
{
	int a = 4, b = 5;
	cout<<a++<<" "<<a++<<endl;
	b = a++ + a--;
	cout << "b : " << b << endl;
	a = ++b + b--;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	return 0;
}