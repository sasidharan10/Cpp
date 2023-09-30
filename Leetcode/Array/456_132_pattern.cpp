#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        bool res = false;
        for (int i = 0; i < n - 2; i++)
        {
            int a = i, b = i - 1, c = i - 2;
            if (nums[a] < nums[b] && nums[a] < nums[c] && nums[b] < nums[c]);
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 1, 4, 2};
    cout << "132 Pattern? : " << s.find132pattern(nums);
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/