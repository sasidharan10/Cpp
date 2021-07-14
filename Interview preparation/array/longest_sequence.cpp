#include <iostream>
#include <algorithm>
using namespace std;
int LongestSubseq(int *a, int n)
{
    int count = 1, ans = 1;
    sort(a, a + n);
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] == a[i])
            continue;
        else if (a[i - 1] == a[i] - 1)
            count++;
        else
            count = 1;
        ans = max(count, ans);
    }
    return ans;
}
int main()
{
    int arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42};
    int n = sizeof arr / sizeof arr[0];
    cout << "Length of the Longest contiguous subsequence is " << LongestSubseq(arr, n);
    return 0;
}