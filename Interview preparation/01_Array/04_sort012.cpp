#include <iostream>
#include <algorithm>
using namespace std;
void segregate1(int *a, int n)
{
    // TC: O(n) 2 traversal
    // SC: O(1)

    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            c0++;
        if (a[i] == 1)
            c1++;
    }
    int i = 0;
    while (c0 > 0)
    {
        a[i++] = 0;
        c0--;
    }
    while (c1 > 0)
    {
        a[i++] = 1;
        c1--;
    }
    while (n > i)
    {
        a[i++] = 2;
    }
    cout << "\nSorted array (2 traversal) : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void segregate2(int *a, int n)
{
    // TC: O(n) 1 traversal
    // SC: O(1)

    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (a[mid] == 0)
            swap(a[mid++], a[low++]);
        else if (a[mid] == 2)
            swap(a[mid], a[high--]);
        else if (a[mid] == 1)
            mid++;
    }
    cout << "\nSorted array (1 traversal) : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int arr1[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // int arr2[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr2[] = {2, 0, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    segregate1(arr1, n1);
    segregate2(arr2, n2);
    return 0;
}

/*

Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that
sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.

link: https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

leetcode: https://leetcode.com/problems/sort-colors/description/

*/
