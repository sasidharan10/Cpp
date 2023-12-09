#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int zeroes = 0;
        int maxi = INT_MIN;
        int i = 0, j = 0;
        int len = 0;
        while (j < n)
        {
            // case 1
            if (nums[j] == 1)
            {
                j++;
            }
            // case 2
            else if (nums[j] == 0 && zeroes < 1)
            {
                j++;
                zeroes++;
            }
            // case 3
            else
            {
                while (nums[i] != 0)
                {
                    i++;
                }
                i++;
                zeroes--;
            }
            len = j - i - 1;
            maxi = max(maxi, len);
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    vector<int> nums{0, 1, 1, 1, 0, 1, 1, 0, 1};
    int k = 3;
    cout << "Longest Subarray of 1's After Deleting One Element: ";
    cout << s.longestSubarray(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

Refer LC 1004
Youtube: https://www.youtube.com/watch?v=Gl-8HLvV8bc

algorithm:

- Dynamic sliding window
- case 1: if nums[j] == 1, we increase the window size.
- case 2: if nums[j] == 0 but zeroes < 1, we can increase the window size
  (can delete one '0').
- case 3: Now we have encountered 1 extra '0', hence we move the left pointer forward,
  until we eliminate one '0', to make the (zeroes < 1).
- We calculate the window size(minus 1, to delete 1 element from the subarray), and update the maxi.

*/

/*

1493. Longest Subarray of 1's After Deleting One Element

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's
in the resulting array. Return 0 if there is no such subarray.

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest
subarray with value of 1's is [1,1,1,1,1].

Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

*/