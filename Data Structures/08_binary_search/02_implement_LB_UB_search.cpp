#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lowerBound(vector<int> arr, int n, int x)
    {
        // TC: O(logN)
        // SC: O(1)

        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> arr, int n, int x)
    {
        // TC: O(logN)
        // SC: O(1)

        int low = 0;
        int high = n - 1;
        int ans = n;
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
        return ans;
    }
    pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
    {
        pair<int, int> ans;
        int cl = lowerBound(a, n, x);
        int low = 0;
        int high = n - 1;
        int fl = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (a[mid] <= x)
            {
                fl = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (fl != n)
            ans.first = a[fl];
        else
            ans.first = -1;
        if (cl != n)
            ans.second = a[cl];
        else
            ans.second = -1;
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 5, 8, 8, 8, 10};
    int n = nums.size();
    int x = 8;
    int index = s.lowerBound(nums, n, x);
    cout << "Lower Bound: " << nums[index] << endl;
    index = s.upperBound(nums, n, x);
    cout << "Upper Bound: " << nums[index] << endl;
    pair<int, int> ans = s.getFloorAndCeil(nums, n, 6);
    cout << "Floor and Ceil of X: " << ans.first << " : " << ans.second << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/lower-bound_8165382
link: https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383

leetcode:

Youtube:

algorithm:

*/