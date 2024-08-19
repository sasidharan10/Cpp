#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    long long maxPointsRecur(int row, int col, int n, int m, vector<vector<int>> &points)
    {
        if (row == n)
            return 0;

        long long maxi = INT_MIN;
        for (int j = 0; j < m; j++)
        {
            int cost = abs(col - j);
            long long temp = points[row][j] + maxPointsRecur(row + 1, j, n, m, points) - cost;
            maxi = max(maxi, temp);
        }
        return maxi;
    }

    // Memoization
    long long maxPointsMem(int row, int col, int n, int m, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        if (row == n)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        long long maxi = INT_MIN;
        for (int j = 0; j < m; j++)
        {
            int cost = abs(col - j);
            long long temp = points[row][j] + maxPointsMem(row + 1, j, n, m, points, dp) - cost;
            maxi = max(maxi, temp);
        }
        return dp[row][col] = maxi;
    }

    long long maxPoints3(vector<vector<int>> &points)
    {
        // TC: O(m*m^n)
        // SC: O(m*n)

        int n = points.size();
        int m = points[0].size();
        long long maxi = INT_MIN;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int j = 0; j < m; j++)
        {
            // long long temp = points[0][j] + maxPointsRecur(1, j, n, m, points);
            long long temp = points[0][j] + maxPointsMem(1, j, n, m, points, dp);
            maxi = max(maxi, temp);
        }
        return maxi;
    }

    // Tabulation
    long long maxPoints2(vector<vector<int>> &points)
    {
        // TC: O(n*m*m)
        // SC: O(m)

        int n = points.size();
        int m = points[0].size();
        long long maxi = INT_MIN;
        vector<long long> prev(m, 0);
        for (int i = 0; i < m; i++)
        {
            prev[i] = points[0][i];
        }

        for (int row = 1; row < n; row++)
        {
            vector<long long> curr(m, 0);
            for (int col = 0; col < m; col++)
            {
                // calculating max using prev row
                for (int k = 0; k < m; k++)
                {
                    curr[col] = max(curr[col], points[row][col] + prev[k] - abs(col - k));
                }
            }
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }

    // Optimised Tabulation
    long long maxPoints(vector<vector<int>> &points)
    {
        // TC: O(n*3m) ~= O(n*m)
        // SC: O(m)

        int n = points.size();
        int m = points[0].size();
        long long maxi = INT_MIN;
        vector<long long> prev(m, 0);
        for (int i = 0; i < m; i++)
        {
            prev[i] = points[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            vector<long long> left(m, 0);
            left[0] = prev[0];
            for (int j = 1; j < m; j++)
            {
                left[j] = max(prev[j], left[j - 1] - 1);
            }
            vector<long long> right(m, 0);
            right[m - 1] = prev[m - 1];
            for (int j = m - 2; j >= 0; j--)
            {
                right[j] = max(prev[j], right[j + 1] - 1);
            }
            vector<long long> curr(m, 0);
            for (int j = 0; j < m; j++)
            {
                curr[j] = max(left[j], right[j]) + points[i][j];
            }

            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> nums{{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    vector<vector<int>> nums{{1, 5}, {2, 3}, {4, 2}};
    cout << "Maximum Number of Points with Cost: " << s.maxPoints(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-number-of-points-with-cost/

Youtube: https://www.youtube.com/watch?v=0AlKD9rZfm4

Code link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Maximum%20Number%20of%20Points%20with%20Cost.cpp

algorithm:

- Brute Force Approach:

- Recursion + Memoization.

- Optimal Approach:

- DP using tabulation
- Refer video, explanation not completed.

*/

/*

1937. Maximum Number of Points with Cost

You are given an m x n integer matrix points (0-indexed). Starting with 0 points,
you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell
at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell
that you picked in the previous row. For every two adjacent rows r and r + 1
(where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2)
will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.

Example 1:

Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9

Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.

Example 2:

Input: points = [[1,5],[2,3],[4,2]]
Output: 11

Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.

*/