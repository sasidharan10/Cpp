#include <bits/stdc++.h>
using namespace std;
int maxProduct2(vector<int> &nums)
{
    // Time : O(n^2)
    // Space : O(1)

    int n = nums.size();
    int result = nums[0], prod = 1;
    for (int i = 0; i < n; i++)
    {
        prod = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            prod *= nums[j];
        }
        result = max(result, prod);
    }
    return result;
}
int maxProduct(vector<int> &nums)
{
    // Time : O(n)
    // Space : O(1)

    int n = nums.size();
    int maxi = INT_MIN;
    int prefix = 1;
    int suffix = 1;
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix = prefix * nums[i];
        suffix = suffix * nums[n - i - 1];
        maxi = max({prefix, suffix, maxi});
    }
    return maxi;
}
int main()
{
    // int a[] = {6, -3, -10, 0, 2};
    vector<int> nums{1, -2, -3, 0, 7, -8, -2};
    cout << "Max Prod O(n^2) : " << maxProduct(nums) << endl;
    cout << "Max Prod O(n)   : " << maxProduct(nums) << endl;
    return 0;
}