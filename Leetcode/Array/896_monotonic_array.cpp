#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool inc = true, dec = true;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
                inc = false;
            if (nums[i - 1] < nums[i])
                dec = false;
        }
        return inc | dec;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{1, 2, 2, 3};
    // vector<int> nums{6, 5, 4, 4};
    vector<int> nums{1, 3, 2};
    cout << "Is array Monotonic?: " << s.isMonotonic(nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/monotonic-array/

Youtube:

algorithm:

*/