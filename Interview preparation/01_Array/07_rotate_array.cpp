#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void rotateRight1(int *a, int n)
{
    // TC: O(n)
    // SC: O(1)

    int i = 0, j = n - 1;
    while (i != j)
    {
        swap(a[i], a[j]);
        i++;
    }
    cout << "\nArray Right rotation : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void rotateRight2(int *a, int n, int r)
{
    // TC: O(n*r)
    // SC: O(1)

    int last = 0;
    r = r % n;
    while (r > 0)
    {
        last = a[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = last;
        r--;
    }
    cout << "\nArray Right rotation (normal): ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void rotateRight3(int *a, int n, int r)
{
    // TC: O(3n)
    // SC: O(1)

    r = r % n;
    reverse(a, a + n);
    reverse(a, a + r);
    reverse(a + r, a + n);
    cout << "\nArray right rotation (optimised): ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void rotateLeft1(int *a, int n)
{

    // TC: O(n*r)
    // SC: O(1)

    int r = 2; // no of rotations
    while (r > 0)
    {
        int i = 0, j = n - 1;
        while (i != j)
        {
            swap(a[i], a[j]);
            j--;
        }
        r--;
    }
    cout << "\nArray Left rotation : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[]{1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    rotateRight1(a, n);
    rotateLeft1(a, n);
    int r = 3;
    rotateRight2(a, n, r);
    rotateRight3(a, n, r);
    return 0;
}

/*

link: https://www.geeksforgeeks.org/c-program-cyclically-rotate-array-one/

leetcode: https://leetcode.com/problems/rotate-array/description/

*/