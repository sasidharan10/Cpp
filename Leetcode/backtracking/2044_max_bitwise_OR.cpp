#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxBitwiseOR;
    int solve(int idx, int n, int curBitwise, vector<int> &nums)
    {
        if (idx == n)
        {
            if (curBitwise == maxBitwiseOR)
                return 1;
            else
                return 0;
        }
        int notPick = solve(idx + 1, n, curBitwise, nums);
        int pick = solve(idx + 1, n, curBitwise | nums[idx], nums);
        return pick + notPick;
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        maxBitwiseOR = 0;
        for (int i = 0; i < n; i++)
        {
            maxBitwiseOR |= nums[i];
        }
        return solve(0, n, 0, nums);
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 2, 1, 5};
    cout << "Result: " << s.countMaxOrSubsets(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

2044. Count Number of Maximum Bitwise-OR Subsets




*/

/*
************* Java Code **************



*/