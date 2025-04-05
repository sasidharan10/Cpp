#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int ind, int n, vector<int> &nums, vector<bool> &vis, vector<int> &tuple)
    {
        if (ind == 4)
        {
            int ab = tuple[0] * tuple[1];
            int cd = tuple[2] * tuple[3];
            if (ab == cd)
                return 1;
            else
                return 0;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vis[i] = true;
                tuple[ind] = nums[i];
                res += solve(ind + 1, n, nums, vis, tuple);
                vis[i] = false;
            }
        }
        return res;
    }
    int tupleSameProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> vis(n, false);
        vector<int> tuple(4, 0);
        return solve(0, n, nums, vis, tuple);
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, 3, 4, 6};
    vector<int> nums{1, 2, 4, 5, 10};
    cout << "Result: " << s.tupleSameProduct(nums) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*






*/

/*
************* Java Code **************



*/