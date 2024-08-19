#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int minStepsRecur(int currStr, int clipStr, int n)
    {
        if (currStr > n)
            return 1e9;
        if (currStr == n)
            return 0;
        int paste = 1 + minStepsRecur(currStr + clipStr, clipStr, n);
        int copyAllPaste = 2 + minStepsRecur(currStr * 2, currStr, n);
        return min(paste, copyAllPaste);
    }
    // Memoization
    int minStepsMem(int currStr, int clipStr, int n, vector<vector<int>> &dp)
    {
        if (currStr > n)
            return 1e9;
        if (currStr == n)
            return 0;
        if (dp[currStr][clipStr] != -1)
            return dp[currStr][clipStr];
        int paste = 1 + minStepsMem(currStr + clipStr, clipStr, n, dp);
        int copyAllPaste = 2 + minStepsMem(currStr * 2, currStr, n, dp);
        return dp[currStr][clipStr] = min(paste, copyAllPaste);
    }
    // Tabulation

    // Space Optimization

    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return 1 + minStepsRecur(1, 1, n);
        return 1 + minStepsMem(1, 1, n, dp);
    }
};
int main()
{
    Solution s;
    int n = 8;
    cout << "Result: " << s.minSteps(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/2-keys-keyboard

Youtube: https://www.youtube.com/watch?v=zELBK8_vB7Y

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/2%20Keys%20Keyboard.cpp

algorithm:

- Brute Force Approach:

- Recursion + Memoization.

- Optimal Approach:

- Pending, refer video.

*/

/*

650. 2 Keys Keyboard

There is only one character 'A' on the screen of a notepad. You can perform one of two operations
on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly
n times on the screen.

Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Example 2:

Input: n = 1
Output: 0

Constraints:

1 <= n <= 1000

*/

/*
************* Java Code **************



*/