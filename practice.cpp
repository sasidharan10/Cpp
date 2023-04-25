#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
void rotateRight1(int *a, int n)
{
    int r=3;
    while (r>0)
    {
        int first=a[0];
        for (int i = 0; i < n; i++)
        {
            a[i]=a[i+1];
        }
        a[n-1]=first;
        r--;
    }
    cout << "\nArray right rotation (optimised): ";
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

    return 0;
}