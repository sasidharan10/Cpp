#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int j = 1;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                nums[j] = nums[i + 1];
                j++;
            }
        }
        return j;
    }
};
int main()
{
    Solution s;
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = s.removeDuplicates(nums);
    vector<int> ans(nums.begin(), nums.begin() + n);
    cout << "Array after Shifting duplicates to the end: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/