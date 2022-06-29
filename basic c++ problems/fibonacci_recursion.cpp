#include <iostream>
#include <cmath>
using namespace std;
int fib1(int x)
{
    if (x <= 1)
        return x;
    else
        return fib1(x - 1) + fib1(x - 2);
}
int fib2(int x)
{
    int a = 0;
    int b = 1;
    int c = a + b;
    if (x == 0)
        return a;
    for (int i = 2; i <= x; i++)
    {
        // cout<<c<<" ";
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
int fib3(int x)
{
    // Formula = {[(√5 + 1)/2] ^ n} / √5
    double phi = (sqrt(5) + 1) / 2;
    return round(pow(phi, x) / sqrt(5));
}
int main()
{
    int x = 9;
    cout << "fibonacci series : ";
    cout << fib1(x);
    cout << "\nfibonacci series (loop) : ";
    cout << fib2(x);
    cout << "\nfibonacci series (O(logn)) : ";
    cout << fib3(x);
    return 0;
}