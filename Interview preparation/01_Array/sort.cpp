#include <iostream>
#include <algorithm>
using namespace std;
void sortArray(int *a, int n)
{
    int hole = 0, key = 0;
    for (int i = 1; i < n; i++)
    {
        hole = i;
        key = a[i];
        while (hole > 0 && a[hole - 1] > key)
        {
            a[hole] = a[hole - 1];
            hole--;
        }
        a[hole] = key;
    }
    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[] = {6, 5, 8, 4, 9, 10, 7, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    sortArray(a, n);

    // by library

    sort(a, a + n);
    cout << "\nSorted array by library : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

// program to sort the given array