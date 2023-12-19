#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        // TC: O(n*m*9)
        // SC: O(n*m)

        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                int div = 0;
                int sum = 0;
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int newRow = row + i;
                        int newCol = col + j;
                        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
                        {
                            sum += img[newRow][newCol];
                            div++;
                        }
                    }
                }
                ans[row][col] = sum / div;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
    vector<vector<int>> ans = s.imageSmoother(nums);
    cout << "Result: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/

/*






*/