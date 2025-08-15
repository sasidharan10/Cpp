#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // TC: O(logN)
        // SC: O(1)

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 3, 5, 6};
    int target = 2;
    cout << "Result: " << s.searchInsert(nums, target) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/search-insert-position/description/

Youtube:

algorithm:

- Finding LB of the target
*/