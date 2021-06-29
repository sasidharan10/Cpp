#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int a[] {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << *max_element(a, a) << endl;//[1,1)
	cout << *max_element(a, a + 1) << endl;//(1,2) but last element is ignored
	// when  range is specified the last element is ignored
	cout << *max_element(a, a + 2) << endl;//[1,2,3)
	cout << *max_element(a, a + 8) << endl;
	cout << *max_element(a, a + 9) << endl;//last element
	// min
	cout << *min_element(a, a) << endl;
	cout << *min_element(a, a + 1) << endl;
	cout << *min_element(a, a + 2) << endl;
	cout << *min_element(a + 3, a + 5) << endl;
	cout << *min_element(a + 5, a + 8) << endl;
	// when  range is specified the last element is ignored
}
