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
        if (n == 1)
            return nums[0];
        int low = 0;
        int high = n - 1;
        int mini = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                if (nums[low] < mini)
                    mini = nums[low];
                low++;
                high--;
                continue;
            }
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
    // vector<int> nums{2, 2, 2, 0, 1};
    // vector<int> nums{3,1,3};
    vector<int> nums{1, 1};
    cout << "Find Minimum in Rotated Sorted Array(With Duplicates): " << s.findMin(nums) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/rotated-array_1093219

leetcode: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Youtube: https://www.youtube.com/watch?v=nhEMDKMB44g&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=9

algorithm:

- Get smallest element in the sorted half, and then eliminate the sorted half, do this untill
  the binary search ends. return the updated smallest element.

*/
