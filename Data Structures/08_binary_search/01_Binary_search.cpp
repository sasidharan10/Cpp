#include <iostream>
#include <climits> // to use INT_MIN
using namespace std;
int binary(int ar[], int n, int x)
{
	int mid = 0, beg, end;
	beg = 0;
	end = n - 1;
	while (beg <= end)
	{
		mid = beg + ((end - beg) / 2); // subtracting first to avoid overflow
		if (ar[mid] == x)
			return mid;
		else if (x > ar[mid])
			beg = mid + 1;
		else
			end = mid - 1;
	}
	return INT_MIN;
}

int main()
{
	int ar[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n, ans = 0;
	n = sizeof(ar) / sizeof(ar[0]);
	int x = 9;
	ans = binary(ar, n, x);
	if (ans != INT_MIN)
		cout << "Found at index : " << ans << endl;
	else
		cout << "Not found!!!";
}

/*

Binary search is applicable in sorted array only

leetcode: https://leetcode.com/problems/binary-search/

*/


