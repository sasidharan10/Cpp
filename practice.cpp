#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
using namespace std;
void mergeSorted(int *a, int n, int *b, int m)
{
    // float k;
    // k=m+n;
    // k=ceil(k/2);
    // for (int i = 0; i < n+m; i++)
    // {
    //     if()
    // }

    sort(a, a + n);
    sort(b, b + m);

    for (int i = m - 1; i >= 0; i--)
    {
        int last = a[n - 1];
        int j;
        for (j = n - 2; j >= 0 && a[j] > b[i]; j--)
        {
            a[j + 1] = a[j];
        }
        if (j != n - 2 && last > b[i])
        {
            a[j + 1] = b[i];
            b[i] = last;
        }
    }
}
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m-1;
    int j = n-1;
    int k = m + n - 1;
    while (i>=0 && j>=0)
    {
        if(nums1[i]>=nums2[j])
            nums1[k--]=nums1[i--];
        if(nums2[j]>nums1[i])
            nums1[k--]=nums2[j--];
    }
    while (i>=0)
    {
        nums1[k--]=nums1[i--];
    }
    while (j>=0)
    {
        nums1[k--]=nums2[j--];
    }
    
    
}
int main()
{
    int a[] = {2, 3, 5, 6, 8};
    int b[] = {1, 4, 7, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    // cout << n << endl;
    // cout << m << endl;
    mergeSorted(a, n, b, m);
    cout << "Sorted Array O(m*n): ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (int j = 0; j < m; j++)
    {
        cout << b[j] << " ";
    }

    return 0;
}