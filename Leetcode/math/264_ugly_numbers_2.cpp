#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> t(n + 1);
        // t[i] = ith Ugly number;
        // we will reutrn t[n] = nth ugly number

        t[1] = 1; // 1st Ugly number

        int i2; // i2th Ugly number
        int i3; // i3rd Ugly number
        int i5; // i5th Ugly number

        // initially i2th, i3rd and i5th Ugly number point to 1 i.e. first ugly number
        i2 = i3 = i5 = 1;

        for (int i = 2; i <= n; i++)
        {
            int i2th_ugly = t[i2] * 2;

            int i3rd_ugly = t[i3] * 3;

            int i5th_ugly = t[i5] * 5;

            t[i] = min({i2th_ugly, i3rd_ugly, i5th_ugly});

            if (t[i] == i2th_ugly)
                i2++;

            if (t[i] == i3rd_ugly)
                i3++;

            if (t[i] == i5th_ugly)
                i5++;
        }

        return t[n];
    }
};
int main()
{
    Solution s;
    int n = 10;
    cout << "Result: " << s.nthUglyNumber(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/ugly-number-ii

Youtube: https://www.youtube.com/watch?v=jRacRh6x4go

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Ugly%20Number%20II.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

264. Ugly Number II

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

Constraints:

1 <= n <= 1690

*/

/*
************* Java Code **************



*/