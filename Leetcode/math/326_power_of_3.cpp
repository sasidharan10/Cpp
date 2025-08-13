#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfThree2(int n)
    {
        // TC: O(log3n)
        // SC: O(1)

        if (n <= 0)
            return false; // no negative or zero powers
        while (n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1; // must end at 1 for true
    }

    // Optimal - 
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
        //NOTE :  3^19 = 1162261467
    }
};
int main()
{
    Solution s;
    int n = 27;
    cout << "Result: " << s.isPowerOfThree(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/power-of-three/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- The maximum power of 3 that fits in a 32-bit signed integer is 3¹⁹ = 1162261467.
- If n is a positive divisor of 3¹⁹, then n must be a power of 3 (since 3 is prime).

*/

/*

326. Power of Three

Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33

Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).
 
Constraints:

-2^31 <= n <= 2^31 - 1
 
Follow up: Could you solve it without loops/recursion?


*/

/*
************* Java Code **************

    public boolean isPowerOfThree(int n) {
        if (n <= 0)
            return false; // no negative or zero powers
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1; // must end at 1 for true
    }

*/