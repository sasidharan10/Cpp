#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
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
};
int main()
{
    Solution s;
    vector<int> nums{2, 7, 9, 3, 1};
    cout << "Maximum profit: " << s.rob(nums);
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/house-robber/description/

Youtube: 

algorithm: 

*/