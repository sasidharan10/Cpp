#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    bool containsNearbyDuplicate2(vector<int> &nums, int k)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] == nums[j] && abs(i - j) <= k)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // optimal - sliding window
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = nums.size();
        unordered_set<int> st;
        int i = 0, j = 0;
        while (j < n)
        {
            // step-1
            if (abs(i - j) > k)
            { // abs(i-j) <= k
                st.erase(nums[i]);
                i++; // shrink
            }

            // past me dekha hai nums[j] ?
            if (st.find(nums[j]) != st.end())
            {
                return true;
            }

            st.insert(nums[j]);
            j++;
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 1, 2, 3};
    int k = 2;
    cout << "Result: " << s.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/contains-duplicate-ii/

Youtube: https://www.youtube.com/watch?v=AyiGBwFlMb8

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Contains%20Duplicate%20II.cpp

algorithm:

- Optimal Approach:

- sliding window

*/

/*

219. Contains Duplicate II

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in
the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
0 <= k <= 10^5


*/

/*
************* Java Code **************

    public static boolean containsNearbyDuplicate(int[] nums, int k) {
        int n = nums.length;
        HashSet<Integer> st = new HashSet<>();
        int i = 0, j = 0;
        while (j < n) {
            // step-1
            if (Math.abs(i - j) > k) { // abs(i-j) <= k
                st.remove(nums[i]);
                i++; // shrink
            }

            // past me dekha hai nums[j] ?
            if (st.contains(nums[j])) {
                return true;
            }

            st.add(nums[j]);
            j++;
        }
        return false;
    }

*/