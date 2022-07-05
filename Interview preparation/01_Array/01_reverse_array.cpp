#include <iostream>
#include <algorithm>
using namespace std;
void reverseArray(int *a, int n)
{
    // Time  : O(n)
    // Space : O(1)

    int temp;
    for (int i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        if (i > j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    cout << "Reverse : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    reverseArray(a, n);

    // using library

    cout << "\nReverse using library : ";
    reverse(a, a + n);
    for (int i : a)
        cout << i << " ";
    return 0;
}

// Write a program to reverse an array or string