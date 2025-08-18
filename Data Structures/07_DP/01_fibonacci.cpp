#include <bits/stdc++.h>
using namespace std;
int fib(int n, vector<int> &dp)
{
    // TC: O(n)  memoization
    // SC: O(n) + O(n)

    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int fib2(int n)
{

    // TC: O(n)
    // SC: O(1)

    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << "Fib: " << fib(n, dp) << endl;
    cout << "Fib: " << fib2(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/fibonacci-number/

Youtube: https://www.youtube.com/watch?v=tyB0ztf0DNY

Code Link: https://takeuforward.org/data-structure/dynamic-programming-introduction/

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

509. Fibonacci Number

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that
each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

Constraints:

0 <= n <= 30

*/

/*
************* Java Code **************

    int fib(int n)
    {
        if (n <= 1)
            return n;

        int prev = 1;
        int prev2 = 0;
        for (int i = 2; i <= n; i++)
        {
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

*/