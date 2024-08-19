#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isUgly(int n)
    {
        // TC: O(log2)
        // SC: O(1)
        
        if (n <= 0)
            return false;
        while (n > 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n /= 3;
            else if (n % 5 == 0)
                n /= 5;
            else
                return false;
        }
        return (n == 1);
    }
};
int main()
{
    Solution s;
    int n = 12;
    cout << "Result: " << s.isUgly(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/ugly-number

Youtube: https://www.youtube.com/watch?v=aCylFAah1z4

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Mathematical/Ugly%20Number.cpp

algorithm:


- Optimal Approach:

- Note that, negative numbers are not ugly numbers, hence return false.
- Just divide the number by 2 or 3 or 5,, until the number becomes 1.
- If the resultant number is not 1, return false.

*/

/*

263. Ugly Number

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return true if n is an ugly number.

Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.

Constraints:

-2^31 <= n <= 2^31 - 1

*/

/*
************* Java Code **************

    public boolean isUgly(int n) {
        while (n > 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n /= 3;
            else if (n % 5 == 0)
                n /= 5;
            else
                return false;
        }
        return (n == 1);
    }

*/