#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force.
    void solve(int currNum, int n, int k, int &res)
    {
        if (k == 0)
        {
            res = currNum;
            return;
        }
        if (currNum > n)
            return;
        for (int append = 0; append <= 9; append++)
        {
            int nextNum = currNum * 10 + append;
            k--;
            if (nextNum > n)
                return;
            solve(nextNum, n, k, res);
        }
    }
    int findKthNumber2(int n, int k)
    {
        int res = -1;
        for (int currNum = 1; currNum <= 9; currNum++)
        {
            if (currNum > n)
                break;
            // k--;
            solve(currNum, n, k, res);
        }
        return res;
    }

    // Optimal
    int Count(int n, long curr, long next)
    {
        int count = 0;
        while (curr <= n)
        {
            count += next - curr;
            curr *= 10;
            next *= 10;
            next = min((long)(n + 1), next);
        }
        return count;
    }
    int findKthNumber(int n, int k)
    {
        int curr = 1; // Start with the first number lexicographically
        k--;          // Since we start from the first, we need k-1 more steps

        while (k > 0)
        {
            int step = Count(n, curr, curr + 1); // Count # between `curr` and the next lexicographical number
            if (step <= k)
            {
                // If there are fewer or equal steps than `k`, we can skip this subtree and go to the next sibling
                curr++;
                k -= step;
            }
            else
            {
                // Otherwise, we need to go deeper into the current subtree
                curr *= 10;
                k--; // We're using the current number, so decrement `k`
            }
        }
        return curr;
    }
};
int main()
{
    Solution s;
    int n = 13, k = 2;
    // int n = 2, k = 2;
    cout << "Result: " << s.findKthNumber(n, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order

Youtube: https://www.youtube.com/watch?v=pQ_BQ9J9p-c

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Recursion/K-th%20Smallest%20in%20Lexicographical%20Order.cpp

algorithm:

- Brute Force Approach:

- Refer LC 386. same approach

- Optimal Approach:

- Not completed.

*/

/*

440. K-th Smallest in Lexicographical Order

Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so

the second smallest number is 10.
Example 2:

Input: n = 1, k = 1
Output: 1

Constraints:

1 <= k <= n <= 10^9

*/

/*
************* Java Code **************



*/