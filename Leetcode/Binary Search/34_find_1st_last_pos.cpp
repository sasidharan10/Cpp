#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> searchRange2(vector<int> &nums, int target)
    {
        // TC: O(n)
        // SC: O(1)

        int start = -1, end = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target && start == -1)
            {
                start = i;
                end = i;
            }
            else if (nums[i] == target)
            {
                end = i;
            }
        }
        vector<int> ans(0, 2);
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
    int firstOccurence(vector<int> &nums, int target)
    {
        int first = -1;
        int low = 0, mid = 0, high = nums.size() - 1;
        while (low <= high)
        {
            mid = low + ((high - low) / 2);
            if (nums[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return first;
    }
    int lastOccurence(vector<int> &nums, int target)
    {
        int last = -1;
        int low = 0, mid = 0, high = nums.size() - 1;
        while (low <= high)
        {
            mid = low + ((high - low) / 2);
            if (nums[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return last;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // TC: O(2logN)
        // SC: O(1)

        int first = firstOccurence(nums, target);
        if (first == -1)
        {
            vector<int> ans(2, -1);
            return ans;
        }
        int last = lastOccurence(nums, target);
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> ans = s.searchRange(nums, target);
    cout << "First and Last pos: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

leetcode: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Youtube: https://www.youtube.com/watch?v=hjR1IYVx9lY&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=5

algorithm:

*/