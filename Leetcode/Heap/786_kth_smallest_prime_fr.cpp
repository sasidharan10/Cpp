#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        // TC: O(n^2)*O(logk)
        // SC: O(k)

        int n = arr.size();
        priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, less<pair<float, pair<int, int>>>> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                pq.push({arr[i] / (float)arr[j], {arr[i], arr[j]}});
                if (pq.size() > k)
                    pq.pop();
            }
        }
        vector<int> ans(2);
        ans[0] = pq.top().second.first;
        ans[1] = pq.top().second.second;
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 5};
    int k = 3;
    vector<int> ans = s.kthSmallestPrimeFraction(nums, k);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/k-th-smallest-prime-fraction/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

786. K-th Smallest Prime Fraction

You are given a sorted integer array arr containing 1 and prime numbers, where
all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of
integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

Example 1:

Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.

Example 2:

Input: arr = [1,7], k = 1
Output: [1,7]

*/

/*
************* Java Code **************



*/