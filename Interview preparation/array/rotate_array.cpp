#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void rotateRight1(int *a, int n)
{
    int i = 0, j = n - 1;
    while (i != j)
    {
        swap(a[i], a[j]);
        i++;
    }
    cout << "\nArray Right rotation (method 1): ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void rotateRight2(int *a, int n)
{
    int last = 0;
    int r = 1; // no of rotations
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
    cout << "\nArray Right rotation (method 2): ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void rotateLeft1(int *a, int n)
{
    int r = 2;  // no of rotations
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
    cout << "\nArray Left rotation (method 1): ";
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
    rotateRight2(a, n);
    rotateLeft1(a, n);
    return 0;
}