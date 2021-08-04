#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    // int a[]={1,2,3,4};
    int a[] = {11, 2, 10, 4, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = (sum - a[i]) / (n - 1);
    }
    for (int i : a)
    {
        cout << i << " ";
    }
}