#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int gcd1(int a, int b)
{
    if (b == 0)
        return a;
    return gcd1(b, a % b);
}
int gcd2(int a, int b)
{
    int gcd;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }
    return gcd;
}
int gcd3(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int gcdArray(int *arr, int n)
{
    int result = arr[0];
    for (int i = 0; i < n; i++)
    {
        result = gcd2(arr[i], result);
        if (result == 1)
            return 1;
    }
    return result;
}
int gcdBuiltIn(int a, int b)
{
    return __gcd(a, b);
}
int main()
{
    // greatest common divisor or highest common factor
    int a = 40, b = 50;
    int arr[]{20, 40, 60, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "GCD is(recursion) : " << gcd1(a, b);
    cout << "\nGCD is(loop) : " << gcd2(a, b);
    cout << "\nGCD is(loop, optimized) : " << gcd3(a, b);
    cout << "\nGCD (Built-in) : " << gcdBuiltIn(a, b);
    cout << "\nGCD Array : " << gcdArray(arr, n);
    return 0;
}