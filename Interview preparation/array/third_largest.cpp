#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
void third_largest1(int *a, int n)
{
    int first = a[0], second = 0, third = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > first)
        {
            third = second;
            second = first;
            first = a[i];
        }
        else if (a[i] > second)
        {
            third = second;
            second = a[i];
        }
        else if (a[i] > third)
        {
            third = a[i];
        }
    }
    cout << "First largest element is : " << first << endl;
    cout << "Second largest element is : " << second << endl;
    cout << "Third largest element is : " << third << endl;
}
void third_largest2(int *a, int n)
{
    partial_sort(a, a + 3, a + n, greater<int>());
    cout << "\nFirst largest element is : " << a[0] << endl;
    cout << "Second largest element is : " << a[1] << endl;
    cout << "Third largest element is : " << a[2] << endl;
}
int main()
{
    int a[] = {8, 5, 3, 2, 6, 10, 1, 7, 9};
    int n = sizeof(a) / sizeof(a[0]);
    third_largest1(a, n);
    third_largest2(a, n);
    return 0;
}

/*

partial_sort(a,a+3,a+n,greater<int>())
(start,middle,end,order)

use functional header for greater and less function

*/