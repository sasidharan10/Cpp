#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - Gives TLE
    int smallestDistancePair2(vector<int> &nums, int k)
    {
        // TC: O(n^2 * logk)
        // SC: O(k)

        int n = nums.size();
        priority_queue<int> pq; // max-heap
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = abs(nums[i] - nums[j]);
                if (pq.empty() || diff < pq.top())
                    pq.push(diff);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }

    // Using map
    int smallestDistancePair(vector<int> &nums, int k)
    {
        // TC: O(n^2 * logk)
        // SC: O(k)

        int n = nums.size();
        priority_queue<int, vector<int>, greater<>> pq;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto &&i : mp)
        {
            for (auto &&j : mp)
            {
                int num1 = i.first;
                int num2 = j.first;
                int freq1 = i.second;
                int freq2 = j.second;
                if (num1 == num2)
                    continue;
                if (freq1 > 1)
                {
                    int temp = (freq1 * (freq1 - 1)) / 2;
                    for (int k = 0; k < temp; k++)
                    {
                        pq.push(0);
                    }
                }
                if (freq2 > 1)
                {
                    int temp = (freq2 * (freq2 - 1)) / 2;
                    for (int k = 0; k < temp; k++)
                    {
                        pq.push(0);
                    }
                }
                int diff = abs(num1 - num2);
                int temp = freq1 * freq2;
                for (int k = 0; k < temp; k++)
                {
                    pq.push(diff);
                }
            }
        }
        while (k > 1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 6, 1};
    int k = 3;
    cout << "Result: " << s.smallestDistancePair(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-k-th-smallest-pair-distance/

Youtube: https://www.youtube.com/watch?v=hx8Ssz_3XSs

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Binary%20Search/Find%20K-th%20Smallest%20Pair%20Distance.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- not done

*/

/*

719. Find K-th Smallest Pair Distance

The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the
pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Example 2:

Input: nums = [1,1,1], k = 2
Output: 0

Example 3:

Input: nums = [1,6,1], k = 3
Output: 5

Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2

*/

/*
************* Java Code **************



*/