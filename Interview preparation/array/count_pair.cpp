#include<iostream>
using namespace std;
int func(int *a, int size, int k)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (a[i] - a[j] == k || a[j] - a[i] == k)
				count++;
		}
	}
	return count;
}
int main()
{

	int a[] = {1, 2, 3, 4, 5};
	int k, size, count;
	cout << "Enter the difference : " << endl;
	cin >> k;
	size = sizeof(a) / sizeof(a[0]);
	count = func(a, size, k);
	cout << "The no of pairs are : " << count;
	return 0;
}