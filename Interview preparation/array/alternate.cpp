#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
void alternate(int *a, int n)
{
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        if (a[i] < 0)
            i = i + 2;
        else if (a[j] > 0)
            j = j + 2;
        else
            swap(a[i], a[j]);
    }
    cout << "Array is : ";
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}
int main()
{
    int a[] = {-5, -2, 5, 2, 4, -7, 1, -8, 0, -8};
    int n = sizeof(a) / sizeof(a[0]);
    alternate(a, n);
    return 0;
}