#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int a = 2, b = 5;
    cout << "Before swap : a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "Swap (library): a = " << a << ", b = " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "Swap (normal): a = " << a << ", b = " << b << endl;
    a += b - (b = a);
    cout << "Swap (oneline): a = " << a << ", b = " << b << endl;
    return 0;
}