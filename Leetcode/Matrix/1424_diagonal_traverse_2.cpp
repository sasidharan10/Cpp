#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        // TC: O(n*m)
        // SC: O(n)
        
        int row = nums.size();
        int i = 0, j = 0, col;

        vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            ans.push_back(nums[r][c]);
            if (c == 0 && r + 1 < row)
            {
                q.push({r + 1, c});
            }
            col = nums[r].size();
            if (c + 1 < col)
            {
                q.push({r, c + 1});
            }
        }
        return ans;
    }
    // brute
    vector<int> findDiagonalOrder2(vector<vector<int>> &nums)
    {
        // TC: O(n*m)
        // SC: O(n*m) - map

        int n = nums.size();
        vector<int> ans;
        map<int, vector<int>> mp;
        for (int i = n - 1; i >= 0; i--)
        {
            int m = nums[i].size();
            for (int j = 0; j < m; j++)
            {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        for (auto &&i : mp)
        {
            for (auto &&j : i.second)
            {
                ans.push_back(j);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> nums{[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]};
    vector<vector<int>> nums{{1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16}};
    vector<int> ans = s.findDiagonalOrder(nums);
    cout << "Diagonal Traverse: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/diagonal-traverse-ii

Youtube: https://www.youtube.com/watch?v=5FWc--uZRwo

algorithm:
 
- Using BFS, we can push the next diagonal into the queue.
- Only once we need to push 2 elements, when the col = 0, by adding the 
  cell, in next row.

*/