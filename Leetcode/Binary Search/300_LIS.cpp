#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};
int main()
{
    Solution s;
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Longest Increasing Subsequence: " << s.lengthOfLIS(nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-increasing-subsequence/description/

Youtube: https://www.youtube.com/watch?v=on2hvxBXJH4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=45

algorithm:

*/