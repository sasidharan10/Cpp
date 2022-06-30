#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "*max_element(a, a): " << *max_element(a, a) << endl;		  //[1,1)
	cout << "*max_element(a, a + 1): " << *max_element(a, a + 1) << endl; //(1,2) but last element is ignored
	// when  range is specified the last element is ignored
	cout << "*max_element(a, a + 2): " << *max_element(a, a + 2) << endl; //[1,2,3)
	cout << "*max_element(a, a + 8): " << *max_element(a, a + 8) << endl;
	cout << "*max_element(a, a + 9): " << *max_element(a, a + 9) << endl; // last element
	// min
	cout << "*max_element(a, a): " << *min_element(a, a) << endl;
	cout << "*max_element(a, a + 1): " << *min_element(a, a + 1) << endl;
	cout << "*max_element(a, a + 2): " << *min_element(a, a + 2) << endl;
	cout << "*max_element(a + 3, a + 5): " << *min_element(a + 3, a + 5) << endl;
	cout << "*max_element(a + 5, a + 8): " << *min_element(a + 5, a + 8) << endl;
	// when  range is specified the last element is ignored
}
