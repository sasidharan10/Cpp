#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int upperBound(vector<int> arr, int n, int x)
    {
        // TC: O(logN)
        // SC: O(1)

        int low = 0;
        int high = n - 1;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 5, 8, 8, 8, 10};
    int n = nums.size();
    int x = 8;
    int index = s.upperBound(nums, n, x);
    cout << "Upper Bound: " << nums[index] << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383

leetcode:

Youtube:

algorithm:

*/