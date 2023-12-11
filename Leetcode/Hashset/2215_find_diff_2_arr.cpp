#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        // TC: O(nlogM)
        // SC: O(n) + O(m)

        unordered_set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
        vector<int> ans1, ans2;
        for (auto &&it : set1)
        {
            if (set2.count(it) == 0)
                ans1.push_back(it);
        }
        for (auto &&it : set2)
        {
            if (set1.count(it) == 0)
                ans2.push_back(it);
        }
        vector<vector<int>> ans{ans1, ans2};
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums1{1, 2, 3};
    vector<int> nums2{2, 4, 6};
    vector<vector<int>> ans = s.findDifference(nums1, nums2);
    cout << "The Difference of Two Arrays: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-difference-of-two-arrays

Youtube:

algorithm:

*/

/*

2215. Find the Difference of Two Arrays

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1
and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4
and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since
nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

*/