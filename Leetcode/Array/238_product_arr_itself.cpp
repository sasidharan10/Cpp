#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixSum(n), suffixSum(n), ans(n);
        int pre = 1, suf = 1, j;
        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            pre *= nums[i];
            prefixSum[i] = pre;
            suf *= nums[j];
            suffixSum[j] = suf;
        }
        int temp = 1;
        ans[0] = suffixSum[1];
        for (int i = 1; i < n - 1; i++)
        {
            temp = prefixSum[i - 1] * suffixSum[i + 1];
            ans[i] = temp;
        }
        ans[n - 1] = prefixSum[n - 2];
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{-1, 1, 0, -3, 3};
    vector<int> ans = s.productExceptSelf(nums);
    cout << "Product of Array Except Self: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}