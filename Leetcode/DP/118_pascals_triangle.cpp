#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal
    vector<vector<int>> generate(int numRows)
    {
        vector<int> prev(numRows + 2, 0), cur(numRows + 2, 0);
        vector<vector<int>> ans;
        prev[1] = 1;
        ans.push_back({1});
        if (numRows == 1)
            return ans;
        for (int i = 2; i <= numRows; i++)
        {
            vector<int> temp;
            for (int j = 1; j <= i; j++)
            {
                cur[j] = prev[j - 1] + prev[j];
                temp.push_back(cur[j]);
            }
            ans.push_back(temp);
            prev = cur;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 3;
    vector<vector<int>> ans = s.generate(n);
    cout << "Pascals Triangle " << endl;
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/pascals-triangle/

Youtube:

algorithm:

*/