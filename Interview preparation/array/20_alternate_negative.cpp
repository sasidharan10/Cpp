#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
void alternate1(int *a, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] < 0)
            i++;
        else if (a[j] > 0)
            j--;
        else
            swap(a[i], a[j]);
    }
    if (i == 0 || i == n)
    {
        cout << "\nArray is (not in order) : ";
        for (int k = 0; k < n; k++)
        {
            cout << a[k] << " ";
        }
        return;
    }
    else
    {
        int k = 0;
        while (i < n && k < n)
        {
            swap(a[k], a[i]);
            k = k + 2;
            i++;
        }
    }

    cout << "\nArray is (not in order) : ";
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}
void Rotate(int *a, int i, int j)
{
    if (i < j)
        while (i != j)
        {
            swap(a[i], a[j]);
            i++;
        }
    else
        while (j != i)
        {
            swap(a[i], a[j]);
            j++;
        }
}
void alternate2(int *a, int n)
{
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        if (a[i] < 0)
        {
            i = i + 2;
        }
        else if (a[j] > 0)
        {
            j = j + 2;
        }
        else
        {
            Rotate(a, i, j);
            i = i + 2;
            j = j + 2;
        }
    }
    cout << "\nArray is (wrong): ";
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}

int main()
{
    int a[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    // int a[] = {1, 2, 3, -4, -1, 4};
    // int a[] = {1,3,6,2,5,4};
    int n = sizeof(a) / sizeof(a[0]);
    alternate1(a, n);
    alternate2(a, n);
    return 0;
}