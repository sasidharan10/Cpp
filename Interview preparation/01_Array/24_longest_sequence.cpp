#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
int LongestSubseq1(int *a, int n)
{
    // Time :  O(nlogn)
    // Space :  O(1)

    int count = 1, ans = 1;
    sort(a, a + n);
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] == a[i]) // skip duplicates
            continue;
        else if (a[i - 1] == a[i] - 1) // checking if they are in sequence
            count++;
        else
            count = 1;
        ans = max(count, ans); // updating max sequence
    }
    return ans;
}
int LongestSubseq2(int *a, int n)
{
    // Time :  O(3n) (inserting,traversing,counting)
    // Space :  O(n)

    unordered_set<int> s;
    int count = 0, maxCount = 0;
    ;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (s.find(a[i] - 1) == s.end())
        {
            int current = a[i];
            count = 0;
            while (s.find(current) != s.end())
            {
                count++;
                current++;
            }
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}
int main()
{
    int arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42};
    // int arr[] = {1, 2, 2, 3 };
    int n = sizeof arr / sizeof arr[0];
    cout << "Longest contiguous subsequence : " << LongestSubseq1(arr, n) << endl;
    cout << "Longest contiguous subsequence : " << LongestSubseq2(arr, n) << endl;
    return 0;
}