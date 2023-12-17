#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int tribonacci(int n)
    {
        int a = 0, b = 1, c = 1, d = 0;
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        for (int i = 3; i <= n; i++)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};
int main()
{
    Solution s;
    int n = 25;
    cout << "Nth Tribonacci number: " << s.tribonacci(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/n-th-tribonacci-number

Youtube:

algorithm:

- We just previous values in a, b ,c and compute d, then we assign a,b,c and continue,
  until the loop ends.

*/

/*

1137. N-th Tribonacci Number

The Tribonacci sequence Tn is defined as follows:
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:

Input: n = 25
Output: 1389537

*/