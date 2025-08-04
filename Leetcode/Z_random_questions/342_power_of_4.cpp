#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute
    bool isPowerOfFour2(int n)
    {
        while (n % 4 == 0)
        {
            // cout << n << endl;
            n = n / 4;
        }
        // cout << n << endl;
        if (n == 1)
            return true;
        else
            return false;
    }
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        float x = log(n) / log(4);
        return (x == (int)x);
    }
};
int main()
{
    Solution s;
    int n = 64;
    cout << "Power of 4?: " << s.isPowerOfFour(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/power-of-four

Youtube:

algorithm: x should be a integer, if n is of 4^x.

*/