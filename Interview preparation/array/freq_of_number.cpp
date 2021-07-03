#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[] = {6, 5, 1, 1, 6, 4, 7, 10, 1, 2, 2, 2, 4, 5, 5, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int count = 0;
    int x = 2; // finds its frequenncy
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            count++;
    }
    cout << "Frequency of " << x << " is : " << count;
    return 0;
}

// Given an array, a[], and an element x, find a number of occurrences of x in a[].