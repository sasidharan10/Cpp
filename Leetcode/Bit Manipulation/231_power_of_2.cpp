#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute - simple division
    bool isPowerOfTwo3(int n)
    {
        // TC: O(logn)
        // SC: O(1)
        
        if (n == 1)
            return true;
        while (n > 0)
        {
            if (n == 2)
                return true;
            if (n % 2 != 0)
                return false;
            n /= 2;
        }
        return false;
    }

    // Better - inbuilt function
    bool isPowerOfTwo2(int n)
    {
        // TC: O(logn) or O(1) since the inbuilt function is faster
        // SC: O(1)
        
        if (n < 0)
            return false;
        int res = __builtin_popcount(n);
        return res == 1;
    }

    // optimal - bitwise
    bool isPowerOfTwo(int n)
    {
        // TC: O(1)
        // SC: O(1)
        
        if (n == 0 || n < 0)
            return false;
        return ((n & (n - 1)) == 0);
    }
};
int main()
{
    Solution s;
    int n = 16;
    cout << "Power of 2?: " << s.isPowerOfTwo(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/power-of-two/

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

231. Power of Two

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.



Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:

Input: n = 3
Output: false

*/