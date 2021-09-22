#include <iostream>
#include <algorithm>
using namespace std;
bool sorted(int *a, int n)
{
    if (n == 0 || n == 1)
        return false;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
            return false;
    }
    return true;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    if (sorted(a, n))
        cout << "\nSorted :) " << endl;
    else
        cout << "\nNot Sorted :( " << endl;
}