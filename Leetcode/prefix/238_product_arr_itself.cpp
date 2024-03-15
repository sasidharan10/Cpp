#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute Force
    vector<int> productExceptSelf4(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int prod = 1;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    prod *= nums[j];
            }
            ans[i] = prod;
        }
        return ans;
    }

    // Better - using division
    vector<int> productExceptSelf3(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int productWithoutZeroes = 1;
        int countZeroes = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                countZeroes++;
            else
                productWithoutZeroes *= nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                if (countZeroes > 0)
                    ans[i] = 0;
                else
                    ans[i] = productWithoutZeroes / nums[i];
            }
            else
            {
                if (countZeroes > 1)
                    ans[i] = 0;
                else
                {
                    ans[i] = productWithoutZeroes;
                }
            }
        }
        return ans;
    }

    // Optimal - Using prefix sum
    vector<int> productExceptSelf2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(3n)

        int n = nums.size();
        vector<int> prefixProd(n), suffixProd(n), ans(n);
        prefixProd[0] = 1;
        suffixProd[n - 1] = 1;
        int pre = 1, suf = 1, j;
        for (int i = 1; i < n; i++)
        {
            prefixProd[i] = nums[i - 1] * prefixProd[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suffixProd[i] = nums[i + 1] * suffixProd[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = prefixProd[i] * suffixProd[i];
        }
        return ans;
    }

    // More Optimal - Using prefix sum, but less space
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; i++)
        {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        int rightProd = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = ans[i] * rightProd;
            rightProd *= nums[i];
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    vector<int> ans = s.productExceptSelf(nums);
    cout << "Product of Array Except Self: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/product-of-array-except-self/

Youtube: https://www.youtube.com/watch?v=ku4oITayEmk

algorithm:

*/

/*

238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i]
is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

*/

/*

public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        int rightProd = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * rightProd;
            rightProd *= nums[i];
        }
        return ans;
    }

*/