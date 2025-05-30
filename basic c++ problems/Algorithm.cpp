#include <bits/stdc++.h>
using namespace std;
int main()
{

	char b[] = "hushvoaiaddv";
	string a = (string)b; // convert to string
	// string a(b);
	cout << a << endl;
	cout << a.size() << endl;
	sort(a.begin(), a.end());
	sort(a.begin(), a.end(), greater<>()); // decending order
	cout << a << endl;
	cout << "Count of h : " << count(a.begin(), a.end(), 'h') << endl; // count of h
	cout << "max : " << *max_element(a.begin(), a.end()) << endl;
	cout << "min : " << *min_element(a.begin(), a.end()) << endl;
	cout << "finding o : ";
	find(a.begin(), a.end(), 'o') != a.end() ? cout << "Found" << endl : cout << "Not Found" << endl; // finding o
	int arr[] = {1, 2, 3, 4, 3, 2, 1, 4, 5, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	// Syntax = accumulate(first_index, first_index, starting_sum)
	cout << "Sum of array: " << accumulate(arr, arr + n, 0) << endl;

	sort(arr, arr + n); // sort

	// reverse(arr, arr + n); // reverse
	for (int i : arr)
		cout << i << " ";

	auto p = lower_bound(arr, arr + n, 4);
	auto q = upper_bound(arr, arr + n, 4);
	cout << "\nThe lower bound is at position: ";
	cout << p - arr << endl;
	cout << "The upper bound is at position: ";
	cout << q - arr << endl;
	vector<int> v(arr, arr + n);
	cout << "Vector: ";
	for (int i : v)
		cout << i << " ";
	cout << endl;
	v.erase(v.begin() + 6);
	cout << "Vector after erasing: ";
	for (int i : v)
		cout << i << " ";
	auto pt = unique(v.begin(), v.end());
	cout << "\nVector after erasing: ";
	for (int i : v)
		cout << i << " ";
	v.erase(pt, v.end());
	cout << "\nVector after removing duplicates: ";
	for (int i : v)
		cout << i << " ";
	cout << "\ndistance of max element : " << distance(v.begin(), max_element(v.begin(), v.end())) << endl;
	vector<int> vec2 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	map<int, int> mp;
	for (int i = 0; i < vec2.size(); i++)
	{
		mp[vec2[i]]++;
	}
	map<int, int>::iterator it = mp.begin();
	advance(it, 2); // 2 steps forward
	cout << "key(2): " << it->first << endl;
	cout << "val(2): " << it->second << endl;
	advance(it, -2); // 2 steps backward
	cout << "key(0): " << it->first << endl;
	cout << "val(0): " << it->second << endl;
	return 0;
}