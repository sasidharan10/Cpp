#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // TC: O(LogN)
        // SC: O(1)

        int n = nums.size();
        if (n == 1)
            return nums[0];
        // if first element is single
        if (nums[0] != nums[1])
            return nums[0];
        // if last element is single
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if ((mid % 2 != 0 && nums[mid - 1] == nums[mid]) || mid % 2 == 0 && nums[mid + 1] == nums[mid])
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
    vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single Element in a Sorted Array: " << s.singleNonDuplicate(nums) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/unique-element-in-sorted-array_1112654

leetcode: https://leetcode.com/problems/single-element-in-a-sorted-array/

Youtube: https://www.youtube.com/watch?v=AZOmHuHadxQ&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=9&t=12s

algorithm:

- before the sinlge element, the pairs are placed in (even, odd) indixes, and
  after the single element, the pairs will be placed in (odd, even) indices.
- Using this, we can eliminate the half, where pairs are placed in (even, odd)
  indices.
*/

/*

540. Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

*/