#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    double myPow2(double x, int n)
    {
        long double ans = 1;
        if (n == 0)
            return 1;
        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                ans *= x;
                cout << ans << endl;
            }
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            ans *= x;
        }
        return 1 / ans;
    }
    // Optimal
    double myPow(double x, int n)
    {
        // TC: O(logn)
        // SC: O(1)

        long nn = n;
        long double ans = 1.0;
        if (nn < 0)
            nn = nn * -1;
        while (nn > 0)
        {
            if (nn % 2 == 1)
            {
                ans = ans * x;
                nn--;
            }
            else
            {
                x *= x;
                nn = nn / 2;
            }
        }
        if (n < 0)
            return (1.0 / ans);
        return ans;
    }
};
int main()
{
    Solution s;
    int x = 2.00000, n = 10;
    cout << "Pow(x, n): " << s.myPow(x, n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/powx-n/description/

Youtube: https://www.youtube.com/watch?v=l0YC3876qxg

algorithm:

- let the power be 'n'
- If n is even, the number ca be written as ans = 1, num = (2)^10 = (2*2)^5 = (4)^5
- If n is odd, then it can be written as ans = 1, num = (4)^5 = 4 * (4)^4
- We repeat this process, until n==0, and return the ans.

- ans = 4, num = (4)^4 = (16)^2
- ans = 4, num = (16)^2 = (256)^1
- ans = 4, num = 256 * (256)^0
- ans = 4 * 256, num = 1.
- ans = 1024, num = 1

*/

/*

50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


*/