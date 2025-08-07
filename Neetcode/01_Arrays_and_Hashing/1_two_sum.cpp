#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    vector<int> twoSum3(vector<int> nums, int target)
    {
        // TC: O(n^2)
        // SC: O(1)

        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }

    // Better - sorting and two pointer
    vector<int> twoSum2(vector<int> &nums, int target)
    {
        // TC: O(nlogn)
        // SC: O(n)

        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int cur = arr[i].first + arr[j].first;
            if (cur == target)
            {
                return {arr[i].second, arr[j].second};
            }
            else if (cur < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {};
    }

    // Optimal - using map
    vector<int> twoSum(vector<int> nums, int target)
    {
        // TC: O(nlogn)
        // SC: O(n)

        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else
                m[nums[i]] = i;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{8, 2, 14, 4, 5, 6};
    int target = 20;
    nums = s.twoSum(nums, target);
    for (auto i : nums)
        cout << i << " ";
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/two-sum/

Youtube: https://www.youtube.com/watch?v=UXDSeD9mN-k

algorithm:

- If index is asked, then use a map, as done above. if not, then sorting the array, and
  use 2 pointer method.

*/

/*

1. Two Sum

Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.

*/

/*
************* Java Code **************

    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];

            if (mp.containsKey(complement)) {
                return new int[] { mp.get(complement), i };
            }
            mp.put(nums[i], i);
        }
        return new int[] {};
    }

*/