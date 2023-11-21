#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        // if first element is peak ,since nums[-1] = -infinity
        if (nums[0] > nums[1])
            return 0;
        // if last element is peak ,since nums[n...] = -infinity
        if (nums[n - 1] > nums[n - 2])
            return n - 1;
        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] > nums[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 1, 3, 5, 6, 4};
    cout << "Peak Element: " << s.findPeakElement(nums) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/find-peak-element_1081482

leetcode: https://leetcode.com/problems/find-peak-element/

Youtube: https://www.youtube.com/watch?v=cXxmbemS6XM&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=10

algorithm:

- Task is to find any 1 peak element.
- if we are ina increasing or decreasing slope, we can never find peak
  hence we eliminate that half, and move to other half, until peak is found
- Edge case will be {1, 5, 1, 2, 1}, here the nums[2], wont satisfy any condition
  as its at the loewst point(opposite of peak), hnce in this case, we
  can move any half, as peak will exist in both.


*/

/*

162. Find Peak Element

A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always
considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2,
or index number 5 where the peak element is 6.


*/