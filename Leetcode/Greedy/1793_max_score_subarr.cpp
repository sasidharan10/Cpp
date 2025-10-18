#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = k;
        int j = k;
        int currMin = nums[k];
        int result = nums[k];
        while (i > 0 || j < n - 1)
        {
            int leftValue = i > 0 ? nums[i - 1] : 0;
            int rightValue = j < n - 1 ? nums[j + 1] : 0;
            if (rightValue > leftValue)
            {
                j++;
                currMin = min(currMin, nums[j]);
                result = max(result, currMin * (j - i + 1));
            }
            else
            {
                i--;
                currMin = min(currMin, nums[i]);
                result = max(result, currMin * (j - i + 1));
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 4, 3, 7, 4, 5};
    int k = 3;
    cout << "Maximum Score of a Good Subarray: " << s.maximumScore(nums, k);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-score-of-a-good-subarray

Youtube: https://www.youtube.com/watch?v=2XMBLBdgqW8&t=1s

algorithm:

*/