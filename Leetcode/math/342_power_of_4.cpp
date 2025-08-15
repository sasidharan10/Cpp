#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute
    bool isPowerOfFour2(int n)
    {
        // TC: log(n) to base 4
        // SC: O(1)
        
        while (n % 4 == 0)
        {
            n = n / 4;
        }

        if (n == 1)
            return true;
        else
            return false;
    }
    bool isPowerOfFour2(int n)
    {
        if (n <= 0)
            return false;
        float x = log(n) / log(4);
        return (x == (int)x);
    }

    // Better
    bool isPowerOfFour(int n)
    {
        // TC: O(log(a))
        // SC: O(1)
        
        if (n <= 0)
            return false;

        int a = (log(n) / log(4));
        /*
            4^a = n
            a = log(n) to base 4
            a = log(n) to base e / log(4) to base e
        */

        if (n == pow(4, a))
            return true;

        return false;
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

Youtube: https://www.youtube.com/watch?v=-2Z4ngPy4H0&t=729s

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Mathematical/Power%20of%20Four.cpp

algorithm: 

- Brute Force Approach:

- use loop

- Optimal Approach:

- using formula

*/

/*

342. Power of Four

Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:

Input: n = 16
Output: true

Example 2:

Input: n = 5
Output: false

Example 3:

Input: n = 1
Output: true

Constraints:

-2^31 <= n <= 2^31 - 1

Follow up: Could you solve it without loops/recursion?

*/

/*   
************* Java Code **************

    public boolean isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        
        int a = (int) (Math.log(n) / Math.log(4));
        
        return n == Math.pow(4, a);
    }

*/