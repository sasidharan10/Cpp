#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
bool findSubArray1(int *a, int *b, int n, int m)
{
    // Time : O(n*m) ~ O(n^2)
    // Space : O(1)

    int j;
    for (int i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (b[i] == a[j])
                break;
        }
        if (j == n)
            return false;
    }
    return true;
}
bool findSubArray2(int *a, int *b, int n, int m)
{
    // Time : O(n)+O(m)
    // Space : O(n)

    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    for (int j = 0; j < m; j++)
    {
        if (s.find(b[j]) == s.end())
            return false;
    }
    return true;
}
bool binarySearch(int *a, int beg, int end, int key)
{
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;
        if (a[mid] == key)
            return true;
        else if (key > a[mid])
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}
bool findSubArray3(int *a, int *b, int n, int m)
{
    // Time : O(nlogn)+O(mlogn)
    // Space : O(n)

    sort(a, a + n);
    for (int i = 0; i < m; i++)
    {
        if (binarySearch(a, 0, n - 1, b[i]) == false)
            return false;
    }
    return true;
}
bool findSubArray4(int *a, int *b, int n, int m)
{
    // Time : O(n)+O(m)
    // Space : O(n)

    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
            return false;
    }
    return (j == m) ? true : false;
}
bool findSubArray5(int *a, int *b, int n, int m)
{
    // Time : O(n)+O(m)
    // Space : O(n)
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    for (int j = 0; j < m; j++)
    {
        if(m[b[j]]>0)
        {
            m[b[j]]--;
        }
        else 
            return false;
    }
    return true;
}
int main()
{
    int a[] = {3, 5, 6, 4, 1, 2};
    int b[] = {1, 2, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    cout << "1) Sub-Array Exists (brute-force) ? : " << findSubArray1(a, b, n, m) << endl;
    cout << "2) Sub-Array Exists (using set) ?   : " << findSubArray2(a, b, n, m) << endl;
    cout << "3) Sub-Array Exists (sorting) ?     : " << findSubArray3(a, b, n, m) << endl;
    cout << "4) Sub-Array Exists (2-pointer) ?   : " << findSubArray4(a, b, n, m) << endl;
    cout << "5) Sub-Array Exists (using map) ?   : " << findSubArray5(a, b, n, m) << endl;
    return 0;
}