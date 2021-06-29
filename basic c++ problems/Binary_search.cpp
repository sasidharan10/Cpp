#include <iostream>
using namespace std;
int binary(int ar[], int n, int x)
{
	int mid = 0, beg, end;
	beg = 0;
	end = n - 1;
	while (beg <= end)
	{
		mid = beg + (end - beg) / 2;
		if (ar[mid] == x)
			return mid;
		else if (x > ar[mid])
			beg = mid + 1;
		else
			end = mid - 1;
	}
	return 0;
}

int main()
{
	int ar[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
	int x, n, ans = 0;
	n = sizeof(ar) / sizeof(ar[0]);
	cout << "Enter the no you want to search " << endl;
	cin >> x;
	ans = binary(ar, n, x);
	if (ans)
		cout << "Found at index : " << ans << endl;
	else
		cout << "Not found!!!";
}
