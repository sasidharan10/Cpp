#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int x)
{
    if (x <= 1)
        return false;
    int n = sqrt(x);
    for (int i = 2; i <= n; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int x = 7;
    if (isPrime(x))
    {
        cout << "The number " << x << " is a prime number." << endl;
    }
    else
        cout << "The number " << x << " is NOT a prime number." << endl;
    return 0;
}
