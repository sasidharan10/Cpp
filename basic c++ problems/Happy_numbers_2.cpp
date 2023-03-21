#include <iostream>
#include <unordered_set>
using namespace std;
int numSquareSum(int x)
{
    int rem = 0, sum = 0;
    while (x > 0)
    {
        rem = x % 10;
        sum += rem * rem;
        x /= 10;
    }
    return sum;
}
bool ishappy1(int n)
{
    unordered_set<int> s;
    while (1)
    {
        n = numSquareSum(n);
        if (n == 1)
            return true;
        if (s.find(n) != s.end())
            return false;
        s.insert(n);
    }
}
bool ishappy2(int n)
{
    // floyd's cycle detection
    int slow = numSquareSum(n);
    int fast = numSquareSum(numSquareSum(n));
    while (slow != fast)
    {
        slow = numSquareSum(slow);
        fast = numSquareSum(numSquareSum(fast));
    }
    return (slow == 1);
}
int main()
{
    int n = 20;
    cout << "Is happy: " << ishappy1(n) << endl;
    cout << "Is happy (Floyd): " << ishappy2(n) << endl;
    return 0;
}