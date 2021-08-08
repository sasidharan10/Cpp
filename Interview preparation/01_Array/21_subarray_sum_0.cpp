#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
bool sum_so_subarray1(int *a, int n)
{
    // Time : O(n^2)
    // Space : O(1)
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == 0)
                return true;
        }
    }
    return false;
}
bool sum_so_subarray2(int *a, int n)
{
    // Time : O(n)
    // Space : O(n)
    int sum;
    unordered_set<int> sumSet;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
        else
            sumSet.insert(sum);
    }
    return false;
}
int main()
{
    int a[] = {-3, 2, 3, -1, -2, 6, 1, -4};
    int n = sizeof(a) / sizeof(a[0]);
    if (sum_so_subarray1(a, n))
        cout << "\nSub-array Exists O(n^2):)" << endl;
    else
        cout << "\nSub-array Does Not Exists O(n^2):(" << endl;
    if (sum_so_subarray2(a, n))
        cout << "Sub-array Exists O(n):)" << endl;
    else
        cout << "Sub-array Does Not Exists O(n):(" << endl;
    return 0;
}

/*

Find if there is a subarray with 0 sum

arr[] = {1, 4, -2, -2, 5, -4, 3}

If we consider all prefix sums, we can notice that there is a subarray with 0
sum when :
1) Either a prefix sum repeats or
2) Or prefix sum becomes 0.

Prefix sums for above array are:
1, 5, 3, 1, 6, 2, 5

Since prefix sum 1 repeats, we have a subarray with 0 sum. 

*/