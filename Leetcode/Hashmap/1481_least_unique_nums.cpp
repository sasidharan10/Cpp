#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // better
    int findLeastNumOfUniqueInts2(vector<int> &arr, int k)
    {
        // TC: O(nlogn)
        // SC: O(n)

        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &&it : mp)
        {
            int freq = it.second;
            pq.push(freq);
        }
        int cnt = pq.size();
        while (k > 0 && !pq.empty())
        {
            int freq = pq.top();
            if (freq <= k)
            {
                k -= freq;
                cnt--;
                pq.pop();
            }
            else
                break;
        }
        return cnt;
    }

    // Optimal
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        // TC: O(n)
        // SC: O(n)

        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        int uniqueTypes = mp.size();
        vector<int> freqCount(n + 1, 0);

        for (auto &&it : mp)
        {
            int freq = it.second;
            freqCount[freq]++;
        }
        for (int freq = 1; freq <= n; freq++)
        {
            int typesICanDelete = min(k / freq, freqCount[freq]);
            k = k - typesICanDelete * freq;
            uniqueTypes = uniqueTypes - typesICanDelete;
            if (k <= freq)
                return uniqueTypes;
        }
        return 0;
    }
};
int main()
{
    Solution s;
    vector<int> nums{4, 3, 1, 1, 3, 3, 2};
    int k = 3;
    cout << "Least unique elements after removing k elements: ";
    cout << s.findLeastNumOfUniqueInts(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

Youtube: https://www.youtube.com/watch?v=O5v9Tqv2ZDA

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

1481. Least Number of Unique Integers after K Removals

Given an array of integers arr and an integer k. Find the least number
of unique integers after removing exactly k elements.

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.

Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

*/