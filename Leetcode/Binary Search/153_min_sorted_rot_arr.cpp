#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // TC: O(LogN)
        // SC: O(1)

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mini = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // left part sorted
            if (nums[low] <= nums[mid])
            {
                if (nums[low] < mini)
                    mini = nums[low];
                low = mid + 1;
            }
            // right part sorted
            else
            {
                if (nums[mid] < mini)
                    mini = nums[mid];
                high = mid - 1;
            }
        }
        return mini;
    }
};
int main()
{
    Solution s;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    cout << "Find Minimum in Rotated Sorted Array: " << s.findMin(nums) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/rotated-array_1093219

leetcode: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Youtube: https://www.youtube.com/watch?v=nhEMDKMB44g&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=9

algorithm:

- We find the smallest element in the sorted half, and then we
  eliminate that half, and move to other half, to find the small element

*/
