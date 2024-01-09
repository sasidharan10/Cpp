#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int start, int k, int n, vector<int> temp)
    {
        if (n == 0)
        {
            if (k == 0)
            {
                ans.push_back(temp);
                return;
            }
            return;
        }
        if (n < 0)
            return;
        for (int i = start; i <= 9; i++)
        {
            if (i <= n)
            {
                temp.push_back(i);
                solve(i + 1, k - 1, n - i, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        solve(1, k, n, {});
        return ans;
    }
};
int main()
{
    Solution s;
    int k = 3, n = 9;
    vector<vector<int>> ans = s.combinationSum3(k, n);
    cout << "All possible Combination sum: " << endl;
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

leetcode: https://leetcode.com/problems/combination-sum-iii

Youtube: https://www.youtube.com/watch?v=rP_K3WJnRR4

algorithm:

*/

/*

216. Combination Sum III

Find all valid combinations of k numbers that sum up to n such that
the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not
contain the same combination twice, and the combinations may be returned in any order.

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can
get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

*/