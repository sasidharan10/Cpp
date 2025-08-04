#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ops = 0;
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 1; i--)
        {
            if (nums[i] == nums[i - 1])
                continue;
            ops += (n - i);
        }
        return ops;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 1, 2, 2, 3};
    cout << "No of Reduction Operations to make Array equal: " << s.reductionOperations(nums) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/