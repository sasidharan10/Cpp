#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    bool checkPowersOfThree3(int n)
    {
        // TC: O(log3n)
        // SC: O(1)

        int p = 0;
        while (pow(3, p) <= n)
        {
            p++;
        }
        while (n > 0)
        {
            if (n >= pow(3, p))
                n = n - pow(3, p);
            if (n >= pow(3, p))
                return false;
            p--;
        }
        return true;
    }

    // using terniary and checking its remainder - refer video
    bool checkPowersOfThree2(int n)
    {
        // TC: O(log3n)
        // SC: O(1)

        while (n > 0)
        {
            if (n % 3 == 2)
                return false;
            n = n / 3;
        }
        return true;
    }

    // using recursion
    bool solve(int p, int n)
    {
        if (n == 0)
            return true;
        if (pow(3, p) > n)
            return false;
        bool take = solve(p + 1, n - pow(3, p));
        bool notTake = solve(p + 1, n);

        return take | notTake;
    }
    bool checkPowersOfThree(int n)
    {
        // TC: O(2 ^ log3n)
        // SC: O(log3n)

        return solve(0, n);
    }
};
int main()
{
    Solution s;
    // int n = 12;
    int n = 21;
    cout << "Result: " << s.checkPowersOfThree(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three

Youtube: https://www.youtube.com/watch?v=BpotFrERzP4

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Mathematical/Check%20if%20Number%20is%20a%20Sum%20of%20Powers%20of%20Three.cpp

algorithm:

- Brute Force Approach:

- Its given, each power should only appear once.

- Optimal Approach:

- refer video

*/

/*

1780. Check if Number is a Sum of Powers of Three

Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three.
Otherwise, return false.
An integer y is a power of three if there exists an integer x such that y == 3x.

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32

Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34

Example 3:

Input: n = 21
Output: false


Constraints:

1 <= n <= 10^7

*/

/*
************* Java Code **************

    public boolean checkPowersOfThree(int n) {
        while (n > 0)
        {
            if (n % 3 == 2)
                return false;
            n = n / 3;
        }
        return true;
    }

*/