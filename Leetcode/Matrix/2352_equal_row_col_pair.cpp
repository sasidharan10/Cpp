#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    int equalPairs2(vector<vector<int>> &grid)
    {
        // TC: O(n^3)
        // SC: O(1)

        int n = grid.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool isEqual = true;
                for (int k = 0; k < n; k++)
                {
                    if (grid[i][k] != grid[k][j])
                    {
                        isEqual = false;
                        break;
                    }
                }
                if (isEqual)
                    cnt++;
            }
        }
        return cnt;
    }
    
    // Optimal
    int equalPairs(vector<vector<int>> &grid)
    {
        // TC: O(n^2)
        // SC: O(n)

        int n = grid.size();
        int cnt = 0;
        map<vector<int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(n, 0);
            int k = 0;
            for (int j = 0; j < n; j++)
            {
                temp[k++] = grid[j][i];
            }
            mp[temp]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mp.find(grid[i]) != mp.end())
                cnt += mp[grid[i]];
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid{{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    cout << "Count of Equal Row and Column Pairs: " << s.equalPairs(grid) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/equal-row-and-column-pairs

Youtube:

algorithm:

*/

/*

2352. Equal Row and Column Pairs

Given a 0-indexed n x n integer matrix grid, return the number of
pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same
elements in the same order (i.e., an equal array).

Example 1:

Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
Example 2:

Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]

*/