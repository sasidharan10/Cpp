#include <iostream>
using namespace std;
int factorial(int x)
{
    if (x == 1)
        return 1;
    else
        return x * factorial(x - 1);
}
int main()
{
    int x = 5;
    cout << "Factorial : ";
    cout << factorial(x) << endl;
    int ans = 1;
    for (int i = 1; i <= x; i++)
    {
        ans *= i;
    }
    cout << "Factorial (loop) : " << ans;
    return 0;
}