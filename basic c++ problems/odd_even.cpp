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
    /*
        - using XOR operation, if no is even, then it increments
          the value, if odd, then decreases by 1
    */
    if ((n ^ 1) == n + 1)
        return true;
    else
        return false;
}
bool oddEven3(int n)
{
    // using AND operation, it will produce 1, if the no is odd, or 0, if even.
    if (n & 1 == 1) // all odd numbers
        return false;
    else
        return true;
}
bool oddEven4(int n)
{
    // using OR operation, if the no is odd, it increases the value by 1.

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