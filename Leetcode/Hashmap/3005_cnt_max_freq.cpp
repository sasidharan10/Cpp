#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal
    int maxFrequencyElements(vector<int> &nums)
    {
        int n = nums.size();
        // unordered_map<int, int> mp;
        vector<int> mp(101, 0);
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int cnt = 0;
        int maxi = 0;
        for (auto freq : mp)
        {
            if (freq > maxi)
            {
                maxi = freq;
                cnt = 1;
            }
            else if (freq == maxi)
                cnt++;
        }
        return cnt * maxi;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 2, 3, 1, 4};
    cout << "Count Max Freq: " << s.maxFrequencyElements(nums) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

3005. Count Elements With Maximum Frequency

You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.

Example 2:

Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.

*/

/*

public int maxFrequencyElements(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }
        int cnt = 0;
        int maxi = 0;
        for (Map.Entry<Integer, Integer> it : mp.entrySet()) {
            int key = it.getKey();
            int freq = it.getValue();
            if (freq > maxi) {
                maxi = freq;
                cnt = 1;
            } else if (freq == maxi)
                cnt++;
        }
        return cnt * maxi;
    }

*/