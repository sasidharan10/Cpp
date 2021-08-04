#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool isPrime1(int n)
{
    // Time : O(n)

    if (n == 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
bool isPrime2(int n)
{
    // Time : O(sqrt(n))

    if (n == 1)
        return false;
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n = 37;
    cout << "Prime ? : " << isPrime1(n) << endl;
    cout << "Prime ? : " << isPrime2(n) << endl;
    return 0;
}