#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        // TC: O(NLogN)
        // SC: O(1)

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        int maxi = INT_MIN;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            maxi = max(maxi, sum);
            i++;
            j--;
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 5, 4, 2, 4, 6};
    cout << "Minimize Maximum Pair Sum in Array: " << s.minPairSum(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

Youtube:

algorithm:

*/