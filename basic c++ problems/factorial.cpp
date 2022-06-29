#include <iostream>
using namespace std;
int factorial1(int x)
{
    if (x == 1)
        return 1;
    else
        return x * factorial1(x - 1);
}
int factorial2(int x)
{
    int ans = 1;
    for (int i = 1; i <= x; i++)
    {
        ans *= i;
    }
    return ans;
}
int main()
{
    int x = 5;
    cout << "Factorial : " << factorial1(x) << endl;
    cout << "Factorial (loop) : " << factorial2(x) << endl;
    return 0;
}