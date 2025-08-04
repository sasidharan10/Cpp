#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        vector<int> temp;
        int newSize = nums.size();
        if (newSize == 1)
            return nums[0];
        int i = 0;
        for (int i = 0; i < newSize - 1; i++)
        {
            int val = (nums[i] + nums[i + 1]) % 10;
            temp.push_back(val);
            if (i == newSize - 2)
            {
                i = -1;
                newSize = temp.size();
                nums = temp;
                temp.clear();
            }
        }
        return temp[0];
    }

    // better
    int triangularSum2(vector<int> &nums)
    {
        int newSize = nums.size();
        if (newSize == 1)
            return nums[0];
        int i = 0;
        for (int i = 0; i < newSize - 1; i++)
        {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
            if (i == newSize - 2)
            {
                i = -1;
                nums.pop_back();
                newSize--;
            }
        }
        return nums[0];
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    cout << "Triangular Array Sum: " << s.triangularSum2(nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-triangular-sum-of-an-array/

Youtube:

algorithm:

*/