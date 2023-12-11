#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLeftIndex(int target, vector<int> &arr)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        int target_idx = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
            {
                target_idx = mid;
                high = mid - 1;
            }
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return target_idx;
    }

    int findRightIndex(int target, vector<int> &arr)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        int target_idx = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
            {
                target_idx = mid;
                low = mid + 1;
            }
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return target_idx;
    }
    // Brute (using frequency count)

    // Better
    int findSpecialInteger2(vector<int> &arr)
    {
        // TC: O(n)
        // SC: O(1)

        int n = arr.size();
        if (n == 1)
            return arr[0];
        int freq = n / 4;
        for (int i = 0; i < n - freq; i++)
        {
            if (arr[i] == arr[i + freq])
            {
                return arr[i];
            }
        }
        return -1;
    }

    // Optimal (binary search)
    int findSpecialInteger(vector<int> &arr)
    {
        // TC: O(3 * logn)
        // SC: O(1)

        int n = arr.size();
        int freq = n / 4;
        // candidates at 25%, 50%, 75% index
        vector<int> candidates{arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        for (int i = 0; i < 3; i++)
        {
            int leftIndex = findLeftIndex(candidates[i], arr);
            int rightIndex = findRightIndex(candidates[i], arr);
            // int leftIndex = lower_bound(arr.begin(), arr.end(), candidates[i]) - arr.begin();
            // int rightIndex = upper_bound(arr.begin(), arr.end(), candidates[i]) - arr.begin() - 1;
            if (rightIndex - leftIndex + 1 > freq)
                return candidates[i];
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 2, 6, 6, 6, 6, 7, 10};
    // vector<int> nums{1, 2, 3, 3};
    cout << "Element Appearing More Than 25% In Sorted Array: " << s.findSpecialInteger(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

Youtube:

algorithm:

- if the element is present more than 25%, and the arr is sorted,
  then  the element is definetly present in any of the 25% inervals.
- Hence we can just check on elements at index 25%, 50%, 75%,
  and see if their count is more than 25%.
- For finding the count, we use binary search to find the first and last occurence
  of that element, then get the count,
- if count > 25%, we return  the result.

*/

/*

1287. Element Appearing More Than 25% In Sorted Array

Given an integer array sorted in non-decreasing order, there is exactly one
integer in the array that occurs more than 25% of the time, return that integer.

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1

*/