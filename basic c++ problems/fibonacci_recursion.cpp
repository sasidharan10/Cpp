#include <iostream>
using namespace std;
int fib(int x)
{
    if (x <= 1)
        return x;
    else
        return fib(x - 1) + fib(x - 2);
}
int main()
{
    int x = 8;
    cout << "fibonacci series : ";
    cout << fib(x);
    return 0;
}