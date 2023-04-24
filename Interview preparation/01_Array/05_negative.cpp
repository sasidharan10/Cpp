#include <iostream>
#include <algorithm>
using namespace std;
void negative(int *a, int n)
{
    // Time : O(n) 1 traversal
    // Space : O(1)

    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        if (a[low] < 0)
            low++;
        else if (a[high] > 0)
            high--;
        else
            swap(a[low++], a[high--]);
    }
    cout << "\nFinal array (method 1) : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[] = {6, -5, -9, 4, -9, 10, -7, 6, 5, -1};
    int n = sizeof(a) / sizeof(a[0]);
    negative(a, n);
    return 0;
}

/*

Move all negative numbers to beginning and positive to end with constant extra space

link: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

*/