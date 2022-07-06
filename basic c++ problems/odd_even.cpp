#include <iostream>
#include <algorithm>
using namespace std;
bool oddEven1(int n)
{
    if (n % 2 == 0)
        return true;
    else
        return false;
}
bool oddEven2(int n)
{
    if ((n ^ 1) == n + 1)
        return true;
    else
        return false;
}
bool oddEven3(int n)
{
    if (!(n & 1))
        return true;
    else
        return false;
}
bool oddEven4(int n)
{
    if ((n | 1) > n)
        return true;
    else
        return false;
}
int main()
{
    int n = 20;
    cout << "Is " << n << " Even?: " << oddEven1(n) << endl;
    cout << "Is " << n << " Even?: " << oddEven2(n) << endl;
    cout << "Is " << n << " Even?: " << oddEven3(n) << endl;
    cout << "Is " << n << " Even?: " << oddEven4(n) << endl;
    return 0;
}