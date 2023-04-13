#include <iostream>
#include <algorithm>
using namespace std;
struct result
{
    int min;
    int max;
};
result minAndMax1(int *a, int n)
{
    result r;
    int max, min;
    if (n == 1)
    {
        r.min = a[0];
        r.max = a[0];
    }
    if (a[0] > a[1])
    {
        r.max = a[0];
        r.min = a[1];
    }
    else
    {
        r.max = a[1];
        r.min = a[0];
    }
    for (int i = 2; i < n; i++)
    {
        if (a[i] > r.max)
            r.max = a[i];
        if (a[i] < r.min)
            r.min = a[i];
    }
    return r;
}
result minAndMax2(int *a, int n)
{
    // we take 2 elements at a time and compare to find max and min
    result r;
    int max, min;
    if (n == 1)
    {
        r.min = a[0];
        r.max = a[0];
    }
    if (a[0] > a[1])
    {
        r.max = a[0];
        r.min = a[1];
    }
    else
    {
        r.max = a[1];
        r.min = a[0];
    }
    for (int i = 2; i < n - 1; i + 2)
    {
        if (a[i] > a[i + 1])
        {
            if (a[i] > r.max)
                r.max = a[i];
            if (a[i + 1] < r.min)
                r.min = a[i + 1];
        }
        else
        {
            if (a[i + 1] > r.max)
                r.max = a[i + 1];
            if (a[i] < r.min)
                r.min = a[i];
        }
    }
    return r;
}
int getMax(int *a, int n)
{
    return (n == 1) ? a[0] : max(a[0], getMax(a + 1, n - 1));
}
int getMin(int *a, int n)
{
    return (n == 1) ? a[0] : min(a[0], getMin(a + 1, n - 1));
}
int main()
{
    result r1, r2;
    int a[] = {21, 23, 56, 65, 34, 54, 76, 32, 23, 45, 21, 23, 25};
    int n = sizeof(a) / sizeof(a[0]);
    r1 = minAndMax1(a, n);
    cout << "Max (normal): " << r1.max << endl;
    cout << "Min (normal): " << r1.min << endl;

    r2 = minAndMax1(a, n);
    cout << "Max (optimised): " << r2.max << endl;
    cout << "Min (optimised): " << r2.min << endl;

    cout << "Max using library: " << *max_element(a, a + n) << endl; // O(n)
    cout << "Min using library: " << *min_element(a, a + n) << endl;

    cout << "Max using recursion : " << getMax(a, n) << endl;
    cout << "Min using recursion : " << getMin(a, n) << endl;
    return 0;
}

// Program to find the minimum and maximum element of an array