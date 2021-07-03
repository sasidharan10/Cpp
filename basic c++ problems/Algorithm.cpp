#include <iostream>
#include <stdio.h>
#include <string> // separate header file to use the string(datatype)
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	char b[] = "hushvoaiaddv";
	string a = (string)b; // convert to string
	// string a(b);
	sort(a.begin(), a.end());
	cout << a << endl;
	cout << "Count of h : " << count(a.begin(), a.end(), 'h') << endl; // count of h
	cout << "max : " << *max_element(a.begin(), a.end()) << endl;
	cout << "min : " << *min_element(a.begin(), a.end()) << endl;
	cout << "finding o : ";
	find(a.begin(), a.end(), 'o') != a.end() ? cout << "Found" << endl : cout << "Not Found" << endl; // finding o
	int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + n);	   // sort
	// reverse(arr, arr + n); // reverse
	for (int i : arr)
		cout << i << " ";
	auto p = lower_bound(arr, arr + n, 20);
	auto q = upper_bound(arr, arr + n, 20);
	cout << "\nThe lower bound is at position: ";
	cout << *p << endl;
	cout << "The upper bound is at position: ";
	cout << *q << endl;
	vector<int> v(arr, arr + n);
	v.erase(v.begin() + 6);
	v.erase(unique(v.begin(), v.end()), v.begin() + 5);
	for (int i : v)
		cout << i << " ";
	cout << "\ndistance : " << distance(v.begin(), max_element(v.begin(), v.end()));
	return 0;
}