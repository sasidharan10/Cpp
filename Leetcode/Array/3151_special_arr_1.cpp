#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal 
    bool isArraySpecial(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = nums.size();
        if (n == 1)
            return true;
        for (int i = 1; i < n; i++)
        {
            bool num1Parity = (nums[i - 1] % 2 == 0) ? true : false;
            bool num2Parity = (nums[i] % 2 == 0) ? true : false;
            if (num1Parity == num2Parity)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, 1, 4};
    vector<int> nums{4, 3, 1, 6};
    cout << "Result: " << s.isArraySpecial(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/special-array-i

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

3151. Special Array I

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

Example 1:

Input: nums = [1]
Output: true
Explanation:

There is only one element. So the answer is true.

Example 2:

Input: nums = [2,1,4]
Output: true
Explanation:

There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

Example 3:

Input: nums = [4,3,1,6]
Output: false
Explanation:

nums[1] and nums[2] are both odd. So the answer is false.

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/

/*
************* Java Code **************

    public boolean isArraySpecial(int[] nums) {
        int n = nums.length;
        if (n == 1)
            return true;
        for (int i = 1; i < n; i++) {
            boolean num1Parity = (nums[i - 1] % 2 == 0) ? true : false;
            boolean num2Parity = (nums[i] % 2 == 0) ? true : false;
            if (num1Parity == num2Parity)
                return false;
        }
        return true;
    }

*/