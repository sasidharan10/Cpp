#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int countArrangement2(int ind, int n, vector<int> &mp)
    {
        if (ind == n + 1)
            return 1;

        int res = 0;
        for (int num = 1; num <= n; num++)
        {
            if (mp[num] == 0 && (num % ind == 0 || ind % num == 0))
            {
                mp[num] = 1;
                res = res + countArrangement2(ind + 1, n, mp);
                mp[num] = 0;
            }
        }
        return res;
    }

    // Better
    int solve(int ind, int n, int seen)
    {
        if (ind == n + 1)
            return 1;

        int res = 0;
        for (int num = 1; num <= n; num++)
        {
            int bit = 1 << num;
            if (((seen & bit) == 0) && (num % ind == 0 || ind % num == 0))
            {
                seen = seen ^ bit;
                res = res + solve(ind + 1, n, seen);
                seen = seen ^ bit;
            }
        }
        return res;
    }

    int countArrangement(int n)
    {
        int res = 0;
        int ind = 1;
        int seen = 0;
        for (int i = 1; i <= n; i++)
        {
            int bit = 1 << i;
            if (i % 1 == 0 || 1 % i == 0)
            {
                seen = seen ^ bit;
                // res = res + countArrangement2(ind + 1, n, mp);
                res = res + solve(ind + 1, n, seen);
                seen = seen ^ bit;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    int n = 4;
    cout << "Result: " << s.countArrangement(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/beautiful-arrangement/

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

526. Beautiful Arrangement

Suppose you have n integers labeled 1 through n. A permutation of those
n integers perm (1-indexed) is considered a beautiful arrangement if for
every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

Example 1:

Input: n = 2
Output: 2
Explanation:
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1

Example 2:

Input: n = 1
Output: 1

*/