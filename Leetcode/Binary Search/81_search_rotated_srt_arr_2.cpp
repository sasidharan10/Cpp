#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        // TC: O(LogN)
        // SC: O(1)

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // left part sorted
            if (nums[mid] == target)
                return true;
            // nums = {3, 3, 1, 2, 3, 3, 3, 3, 3, 3}
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // right part sorted
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    cout << "Element Index in Rotated Sorted Array: " << s.search(nums, target) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/search-in-a-rotated-sorted-array-ii_7449547

leetcode: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Youtube: https://www.youtube.com/watch?v=w2G2W8l__pc&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=6

algorithm:

*/
