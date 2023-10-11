#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int change = 0;
            if (nums[i - 1] >= nums[i])
            {
                change = nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i] + change;
                cnt += change;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 5, 2, 4, 1};
    cout << "Min Operations to make the Array Strictly Increasing: " << s.minOperations(nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

Youtube:

algorithm:

*/