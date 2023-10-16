#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // better
    vector<int> getRow2(int rowIndex)
    {
        vector<vector<int>> ans(rowIndex + 2, vector<int>(rowIndex + 2, 0));
        ans[1][1] = 1;
        for (int i = 2; i <= rowIndex + 1; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        vector<int> temp(ans[rowIndex + 1].begin() + 1, ans[rowIndex + 1].end());
        return temp;
    }
    // Optimal
    vector<int> getRow(int rowIndex)
    {
        vector<int> prev(rowIndex + 2, 0), cur(rowIndex + 2, 0);
        prev[1] = 1;
        for (int i = 2; i <= rowIndex + 1; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cur[j] = prev[j - 1] + prev[j];
            }
            prev = cur;
        }
        vector<int> temp(prev.begin() + 1, prev.end());
        return temp;
    }
};
int main()
{
    Solution s;
    int n = 3;
    vector<int> ans = s.getRow(n);
    cout << "Pascals Triangle, ith row: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/pascals-triangle-ii

Youtube: https://www.youtube.com/watch?v=k1DNTyal77I

algorithm:

*/