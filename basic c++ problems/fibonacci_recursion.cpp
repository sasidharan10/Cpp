#include <iostream>
using namespace std;
int fib(int x)
{
    if (x <= 1)
        return x;
    else
        return fib(x - 1) + fib(x - 2);
}
int fib2(int x)
{
    int a = 0;
    int b = 1;
    int c = a+b;
    if (x == 0 || x == 1)
        return a;
    if (x == 2)
        return b;
    for (int i = 2; i < x; i++)
    {
        cout<<c<<" ";
        c = a + b;
        a = b;
        b = c;
    }
    cout<<endl;
    return b;
}
int main()
{
    int x = 8;
    cout << "fibonacci series : ";
    cout << fib(x);
    cout << endl;
    cout << fib2(x);

    return 0;
}