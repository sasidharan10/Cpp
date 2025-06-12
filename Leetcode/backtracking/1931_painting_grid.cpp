#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    bool checkAdjacentColor(int i, int j, int m, int n, int color, vector<vector<int>> &mp)
    {
        bool res = true;
        if (i + 1 < m)
            res &= mp[i + 1][j] != color;
        if (i - 1 >= 0)
            res &= mp[i - 1][j] != color;
        if (j + 1 < n)
            res &= mp[i][j + 1] != color;
        if (j - 1 >= 0)
            res &= mp[i][j - 1] != color;
        return res;
    }
    int solve(int i, int j, int m, int n, vector<vector<int>> &mp)
    {
        if (i >= m || j >= n && i + 1 >= m)
        {
            return 1;
        }
        if (j >= n)
        {
            j = 0;
            i++;
        }
        long long ans = 0;
        if (checkAdjacentColor(i, j, m, n, 1, mp))
        {
            mp[i][j] = 1;
            ans += solve(i, j + 1, m, n, mp);
            mp[i][j] = 0;
        }
        else if (checkAdjacentColor(i, j, m, n, 2, mp))
        {
            mp[i][j] = 2;
            ans += solve(i, j + 1, m, n, mp);
            mp[i][j] = 0;
        }
        else if (checkAdjacentColor(i, j, m, n, 3, mp))
        {
            mp[i][j] = 3;
            ans += solve(i, j + 1, m, n, mp);
            mp[i][j] = 0;
        }
        return ans % mod;
    }
    int colorTheGrid(int m, int n)
    {
        vector<vector<int>> mp(m, vector<int>(n, 0));
        return solve(0, 0, m, n, mp);
    }
};
int main()
{
    Solution s;
    int m = 5, n = 5;
    // int m = 1, n = 2;
    cout << "Result: " << s.colorTheGrid(m, n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/painting-a-grid-with-three-different-colors

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

1931. Painting a Grid With Three Different Colors

You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can
paint each cell red, green, or blue. All cells must be painted.

Return the number of ways to color the grid with no two adjacent cells having the same color. Since the
answer can be very large, return it modulo 10^9 + 7.

Example 1:

Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.

Example 2:

Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.

Example 3:

Input: m = 5, n = 5
Output: 580986

Constraints:

1 <= m <= 5
1 <= n <= 1000

*/

/*
************* Java Code **************



*/