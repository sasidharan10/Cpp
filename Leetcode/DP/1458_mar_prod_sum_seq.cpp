#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int maxDotProductRecur(int ind1, int ind2, vector<int> &nums1, vector<int> &nums2)
    {
        if (ind1 == 0 || ind2 == 0)
            return 0;
        int r1 = (nums1[ind1 - 1] * nums2[ind2 - 1]) + maxDotProductRecur(ind1 - 1, ind2 - 1, nums1, nums2);
        return max({r1, maxDotProductRecur(ind1 - 1, ind2, nums1, nums2), maxDotProductRecur(ind1, ind2 - 1, nums1, nums2)});
    }
    // Memoization
    int maxDotProductMem(int ind1, int ind2, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (ind1 == 0 || ind2 == 0)
            return 0;
        if (dp[ind1][ind2] != INT_MIN)
            return dp[ind1][ind2];
        int r1 = (nums1[ind1 - 1] * nums2[ind2 - 1]) + maxDotProductMem(ind1 - 1, ind2 - 1, nums1, nums2, dp);
        return dp[ind1][ind2] = max({r1, maxDotProductMem(ind1 - 1, ind2, nums1, nums2, dp), maxDotProductMem(ind1, ind2 - 1, nums1, nums2, dp)});
    }
    // Tabulation
    int maxDotProductTab(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int ind1 = 1; ind1 <= n1; ind1++)
        {
            for (int ind2 = 1; ind2 <= n2; ind2++)
            {
                int r1 = (nums1[ind1 - 1] * nums2[ind2 - 1]) + dp[ind1 - 1][ind2 - 1];
                dp[ind1][ind2] = max({r1, dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]});
            }
        }
        return dp[n1][n2];
    }
    // Space Optimization
    int maxDotProductSpc(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> prev(n2 + 1, 0), cur(n2 + 1, 0);
        for (int ind1 = 1; ind1 <= n1; ind1++)
        {
            for (int ind2 = 1; ind2 <= n2; ind2++)
            {
                int r1 = (nums1[ind1 - 1] * nums2[ind2 - 1]) + prev[ind2 - 1];
                cur[ind2] = max({r1, prev[ind2], cur[ind2 - 1]});
            }
            prev = cur;
        }
        return cur[n2];
    }
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        // Calculate maximum and minimum values for nums1
        for (int num : nums1)
        {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        // Calculate maximum and minimum values for nums2
        for (int num : nums2)
        {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }

        // Check special cases where all elements are negative
        if ((firstMax < 0 && secondMin > 0) || (firstMin > 0 && secondMax < 0))
        {
            return max(firstMax * secondMin, firstMin * secondMax);
        }
        // return maxDotProductRecur(n1, n2, nums1, nums2);
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MIN));
        // return maxDotProductMem(n1, n2, nums1, nums2, dp);
        // return maxDotProductTab(nums1, nums2);
        return maxDotProductSpc(nums1, nums2);
    }
};
int main()
{
    Solution s;
    vector<int> nums1{2, 1, -2, 5};
    vector<int> nums2{3, 0, -6};
    cout << "Max Product Sum Subsequence of 2 Array: " << s.maxDotProduct(nums1, nums2);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/

Youtube:

algorithm:

*/