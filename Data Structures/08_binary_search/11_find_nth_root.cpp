#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    int func2(int x, int n)
    {
        for (int i = 0; i < n; i++)
        {
            x *= x;
        }
        return x;
    }
    int NthRoot2(int n, int m)
    {
        // TC: O(m)
        // SC: O(1)
        
        long long ans = 1;
        for (int i = 1; i <= m; i++)
        {
            long long val = func2(i, n);
            if (val == m)
                return i;
            else if (val > m)
                break;
        }
        return -1;
    }

    int func(int mid, int n, int m)
    {
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans *= mid;
            if (ans > m)
                return 2;
        }
        if (ans == m)
            return 1;
        return 0;
    }
    // Optimal
    int NthRoot(int n, int m)
    {
        // TC: O(Logm)
        // SC: O(1)

        int low = 1, high = m;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            int res = func(mid, n, m);
            if (res == 1)
                return mid;
            else if (res == 2)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    // int n = 4, m = 69;
    int n = 3, m = 27;
    cout << "Nth root: " << s.NthRoot(n, m) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679

leetcode: 

Youtube: https://www.youtube.com/watch?v=rjEJeYCasHs&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=12

algorithm:

- Binary Search

*/

/*

50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


*/