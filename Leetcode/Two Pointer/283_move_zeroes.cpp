#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Using Extra Space
    void moveZeroes3(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        vector<int> temp(n, 0);
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                temp[k++] = nums[i];
            }
        }
        nums = temp;
    }

    // In-Place (we copy the non=zeroes values in front, and assign remaining values as 0)
    void moveZeroes2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int k = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[k++] = nums[i];
            }
        }
        for (int i = k; i < n; i++)
        {
            nums[i] = 0;
        }
    }

    // In-Place using Two Pointers
    void moveZeroes(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int i = 0, j = 0;
        int n = nums.size();
        while (i < n && j < n)
        {
            if (nums[j] != 0)
                swap(nums[i++], nums[j++]);
            else
                j++;
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums{0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    cout << "Array after moving 0's to the end: " << endl;
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/move-zeroes

Youtube:

algorithm:

*/

/*

283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining
the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


*/