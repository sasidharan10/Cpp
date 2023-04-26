#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_end_here = 0;
        int max_so_far = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            max_end_here = nums[i] + max_end_here;
            if (max_end_here > max_so_far)
            {
                max_so_far = max_end_here;
            }
            if (max_end_here < 0)
                max_end_here = 0;
        }
        return max_so_far;
    }
};
int main()
{
    Solution s;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray: " << s.maxSubArray(nums);
    return 0;
}


/*

leetcode: https://leetcode.com/problems/maximum-subarray/description/

*/