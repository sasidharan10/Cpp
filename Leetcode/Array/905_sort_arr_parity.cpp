#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (nums[i] % 2 == 0)
                i++;
            if (nums[j] % 2 != 0)
                j--;
            if (nums[i] % 2 != 0 && nums[j] % 2 == 0)
                swap(nums[i++], nums[j--]);
        }
        return nums;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 1, 2, 4};
    vector<int> ans = s.sortArrayByParity(nums);
    cout << "Array after array sorting by parity: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}