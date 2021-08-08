#include <iostream>
#include <stdio.h>
using namespace std;
bool isSegment(int *a, int n, int x, int s)
{
    int i, j;
    for (i = 0; i < n; i = i + s)
    {
        for (int j = 0; j < s; j++)
        {
            if (a[i + j] == x)
                break;
        }
        if (j == s) // not in segment
            return false;
    }
    if (i == n)
        return true;
    j = 0;
    for (j = i - s; j < n; j++)
    {
        if (a[j] == x)
            break;
    }
    if (j == n)
        return false;
    return true;
}
int main()
{
    int a[] = {21, 23, 56, 65, 34, 54, 76, 32, 23, 45, 21, 23, 25};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 23;
    int s = 5;
    if (isSegment(a, n, x, s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}

/*

Given an array arr[] and size of array is n and one another key x, and give you a segment size k. The task is to find that the key x present in every segment of size k in arr[].
Examples: 

Input : 
arr[] = { 3, 5, 2, 4, 9, 3, 1, 7, 3, 11, 12, 3} 
x = 3 
k = 3 
Output : Yes 
There are 4 non-overlapping segments of size k in the array, {3, 5, 2}, {4, 9, 3}, {1, 7, 3} and {11, 12, 3}. 3 is present all segments.
Input : 
arr[] = { 21, 23, 56, 65, 34, 54, 76, 32, 23, 45, 21, 23, 25} 
x = 23 
k = 5 
Output :Yes 
There are three segments and last segment is not full {21, 23, 56, 65, 34}, {54, 76, 32, 23, 45} and {21, 23, 25}. 
23 is present all window.
Input :arr[] = { 5, 8, 7, 12, 14, 3, 9} 
x = 8 
k = 2 
Output : No

*/