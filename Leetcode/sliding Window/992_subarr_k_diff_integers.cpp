#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int slidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        while (j < n)
        {
            mp[nums[j]]++;
            while (mp.size() > k)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // TC: O(2n) + O(2n) ~ O(n)
        // SC: O(n)
        
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 1, 2, 3};
    int k = 2;
    cout << "Subarrays with K Different Integers: " << s.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/subarrays-with-k-different-integers/

Youtube: https://www.youtube.com/watch?v=uJJSGxfzix8

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- Using sliding window, as we traverse the array, we note the freq of each elements in mp.
- if (mp.size() > k), means we have more than k unique elements, hence we shrink the subarr
  to satisfy the condition.
- Then, we update cnt += (j - i + 1). refer LC 2958
- Lets say k = 3, then cnt will have the count of all subarrs, that has k = 1, k = 2, k = 3
- Example: arr = [1, 2, 1, 2, 3], k = 3
- Sub-arr =>

- {[1], [1,2], [2]}
- {[1, 2, 1], [2, 1], [1]}
- {[1, 2, 1, 2], [2, 1, 2], [1, 2], [2]}
- {[2, 3], [3]}
= 12 subarrays

- arr = [1, 2, 1, 2, 3], k = 3
- Sub-arr =>
- {[1]}
- {[2]}
- {[1]}
- {[2]}
- {[3]}
= 5 subarrays

- to get subarrays, having exactly 3 unique emelements =>
- when k = 3, it will include sub-arrays having k=3, k=2, k=1 unique elements.
- similalry when k = 2, it will include sub-arrays having k=2, k=1 unique elements.
- So, subtracting findAllSubarrays(k) - findAllSubarrays(k - 1), will give the 
  subarray counts having exactly k unique elements.

*/

/*

992. Subarrays with K Different Integers

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers:
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

*/

/*
************* Java Code **************

public static int slidingWindow(int[] nums, int k) {
        int n = nums.length;
        int cnt = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int i = 0, j = 0;
        while (j < n) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            while (mp.size() > k) {
                mp.replace(nums[i], mp.get(nums[i]) - 1);
                if (mp.get(nums[i]) == 0)
                    mp.remove(nums[i]);
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }

    public static int subarraysWithKDistinct(int[] nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }

*/