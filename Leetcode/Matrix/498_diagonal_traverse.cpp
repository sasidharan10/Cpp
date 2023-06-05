#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        // TC: O(m*n)
        // SC: O(1)
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        if (mat.size() == 0)
            return ans;
        int row = 0, col = 0;
        bool up = true;
        while (row < m && col < n)
        {
            if (up)
            {
                while (row > 0 && col < n - 1)
                {
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                ans.push_back(mat[row][col]);
                if (col == n - 1)
                {
                    row++;
                }
                else
                    col++;
            }
            else
            {
                while (row < m - 1 && col > 0)
                {
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                ans.push_back(mat[row][col]);
                if (row == m - 1)
                {
                    col++;
                }
                else
                    row++;
            }
            up = !up;
        }
        return ans;
    }
    vector<int> findDiagonalOrder2(vector<vector<int>> &mat)
    {
        // TC: O(m*n)
        // SC: O(m*n)

        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        map<int, vector<int>> mp;
        int *temp;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mp[i + j].empty())
                {
                    vector<int> temp;
                    temp.push_back(mat[i][j]);
                    mp.insert({i + j, temp});
                }
                mp[i + j].push_back(mat[i][j]);
            }
        }
        bool k = true;
        for (auto &&i : mp)
        {
            if (k)
            {
                reverse(i.second.begin(), i.second.end());
            }
            for (auto &&j : i.second)
            {
                ans.push_back(j);
            }
            k = !k;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = s.findDiagonalOrder2(v);
    cout << "Diagonal Traverse: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/diagonal-traverse/

*/