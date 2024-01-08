#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<pair<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp.push_back({nums1[i], nums2[i]});
        }
        sort(mp.begin(), mp.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> pq;
        long long kSum = 0;
        for (int i = 0; i < k; i++)
        {
            kSum += mp[i].first;
            pq.push(mp[i].first);
        }
        long long res = kSum * mp[k - 1].second;
        for (int i = k; i < n; i++)
        {
            kSum += mp[i].first - pq.top();
            pq.pop();
            pq.push(mp[i].first);
            res = max(res, kSum * mp[i].second);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {1, 3, 3, 2}, nums2 = {2, 1, 3, 4};
    int k = 3;
    cout << "Maximum Subsequence Score: " << s.maxScore(nums1, nums2, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-subsequence-score

Youtube: https://www.youtube.com/watch?v=z9oUzKhEYJU

algorithm:

- as per the question, we have to take sum of k elements from nums1
  and corresponding to its indices n nums2, we have to find the min element
  in nums2 and find the product. We need to find the max product.
- Ex: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3 (more examples below)
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We make a pair of both elements from nums1 and nums2 (to maintain thier order).
- Sort the map by descending order w.r.t to nums2 elements.
- We do this, since we will be traversing the map and we need to get the max
  element from the nums2, so the prod will be max.
- We take kSum variable, where we store nums1's k elements sum.
- And also push its element in priority_queue (min-heap), which helps in
  eliminating smallest element from the kSum, in order to get the max prod.
- As we iterate, we update the kSum, and take the prod, and then update the res.

*/

/*

2542. Maximum Subsequence Score

You are given two 0-indexed integer arrays nums1 and nums2 of equal length n
and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum
of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] ,
nums2[i1], ... ,nums2[ik - 1]).

Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from
the set {0, 1, ..., n-1} by deleting some or no elements.

Example 1:

Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation:
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6.
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12.
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.

Example 2:

Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
Output: 30
Explanation:
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.

*/