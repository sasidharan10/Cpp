#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < m - 2; j++)
            {
                int res = 0;
                for (int c = j; c < j + 3; c++)
                {
                    res += grid[i][c];     // 1st row
                    res += grid[i + 2][c]; // 3rd row
                }
                res += grid[i + 1][j + 1]; // 2nd row
                ans = max(ans, res);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{6, 2, 1, 3}, {4, 2, 1, 5}, {9, 2, 8, 7}, {4, 1, 2, 9}};
    cout << "Max Hourglass Sum: " << s.maxSum(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/

Youtube:

algorithm:

*/