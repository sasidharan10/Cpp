#include <iostream>
#include <array>
using namespace std;
int main()
{
	array<int, 5> a{1, 2, 3, 4, 5};
	array<int, 5> b;
	b = {6, 7, 8, 9, 10};
	//we can initialize array after declaration which is not appplicable for normal array
	cout << "a.at(2) : " << a.at(2) << endl; //throws exception if out of bound
	cout << "get<3>(a) : " << get<3>(a) << endl;
	cout << "a[1] : " << a[1] << endl; //access element
	cout << "a.front() : " << a.front() << endl;
	cout << "a.back() : " << a.back() << endl;
	cout << "a.size() : " << a.size() << endl;
	cout << "a.max_size() : " << a.max_size() << endl;
	a.swap(b);
	cout << "a.empty() : " << a.empty() << endl;
	a.fill(1); //fill aarray with value 1
	return 0;
}