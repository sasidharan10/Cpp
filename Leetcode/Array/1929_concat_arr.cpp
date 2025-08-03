#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal approach
    vector<int> getConcatenation(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(2n)
        
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res.push_back(nums[j]);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 1};
    vector<int> ans = s.getConcatenation(nums);
    cout << "Result: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/concatenation-of-array/

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

1929. Concatenation of Array

Given an integer array nums of length n, you want to create an array ans of length 2n where
ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
Specifically, ans is the concatenation of two nums arrays.
Return the array ans.

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]

Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]

Constraints:

n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000

*/

/*
************* Java Code **************

    public int[] getConcatenation(int[] nums) {
        int[] ans = new int[2 * nums.length];
        int idx = 0;
        for (int i = 0; i < 2; i++) {
            for (int num : nums) {
                ans[idx++] = num;
            }
        }
        return ans;
    }

*/