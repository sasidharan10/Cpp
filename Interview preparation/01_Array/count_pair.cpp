#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int func(int *a, int n, int k)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] - a[j] == k || a[j] - a[i] == k)
			{
				cout << "(" << a[i] << ", " << a[j] << "), ";
				count++;
			}
		}
	}
	return count;
}
int func2(int *a, int n, int k)
{
	sort(a,a+n);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int f = k + a[i];
		if (binary_search(a + i, a + n, f))
		{
			count++;
		}
	}
	return count;
}
int main()
{

	// int a[] = {1, 2, 3, 4, 5};
	int a[] = {5,9,2,3,8,6,7,4,1};
	int k = 3;
	int n = sizeof(a) / sizeof(a[0]);
	cout << "The no of pairs are : " << func(a, n, k) << endl;
	cout << "The no of pairs are : " << func2(a, n, k) << endl;
	return 0;
}