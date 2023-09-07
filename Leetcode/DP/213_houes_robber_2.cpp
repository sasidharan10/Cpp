#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int robUtil(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i - 2 >= 0)
                pick += prev2;
            int notPick = 0 + prev;
            int cur = max(pick, notPick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> temp1, temp2;
        for (int i = 0; i < n - 1; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(robUtil(temp1), robUtil(temp2));
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 1};
    cout << "Maximum profit: " << s.rob(nums);
    return 0;
}


/*

link: 

leetcode: https://leetcode.com/problems/house-robber-ii/description/

Youtube: https://www.youtube.com/watch?v=3WaxQMELSkw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=7

algorithm: 

*/