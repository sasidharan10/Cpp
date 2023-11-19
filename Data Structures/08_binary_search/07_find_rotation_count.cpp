#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKRotation(vector<int> &nums)
    {
        // TC: O(LogN)
        // SC: O(1)

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mini = INT_MAX;
        int index = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // optimised condition
            /*
            if we cross the rotated part, the array will be fully sorted
            hence, we can directly return the smallest element in that sub array
            */
            if (nums[low] <= nums[high])
            {
                if (nums[low] < mini)
                {
                    mini = nums[low];
                    index = low;
                }
                break;
            }
            // left part sorted
            if (nums[low] <= nums[mid])
            {
                if (nums[low] < mini)
                {
                    mini = nums[low];
                    index = low;
                }
                low = mid + 1;
            }
            // right part sorted
            else
            {
                if (nums[mid] < mini)
                {
                    mini = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 4, 5, 1, 2};
    cout << "Find no of Rotation the sorted array: " << s.findKRotation(nums) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/rotation_7449070

leetcode:

Youtube: https://www.youtube.com/watch?v=jtSiWTPLwd0&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=9

algorithm:

- Find the minimum value in the array, its index will be the
  no of times, the array got rotated.
*/