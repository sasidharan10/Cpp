#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - By sorting and using 2 pointers
    vector<int> intersect2(vector<int> &nums1, vector<int> &nums2)
    {
        // TC: O(nlogn) + O(mlogm) + O(n + m)
        // SC: O(1)
        
        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return ans;
    }

    // Optimal - Using map
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        // TC: O(n + m)
        // SC: O(n)

        int n = nums1.size();
        int m = nums2.size();
        vector<int> mp(1001, 0);
        for (int i = 0; i < n; i++)
        {
            mp[nums1[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            if (mp[nums2[i]] > 0)
            {
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    // vector<int> nums1 = {2, 2}, nums2 = {1, 2, 2, 1};
    vector<int> nums1 = {4, 9, 5}, nums2 = {9, 4, 9, 8, 4};
    vector<int> ans = s.intersect2(nums1, nums2);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/intersection-of-two-arrays-ii

Youtube: https://www.youtube.com/watch?v=gRpn4pyXf8I

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Intersection%20of%20Two%20Arrays%20II.cpp

algorithm:


- Optimal Approach:

- self explanatory

*/

/*

350. Intersection of Two Arrays II

Given two integer arrays nums1 and nums2, return an array of their intersection. Each
element in the result must appear as many times as it shows in both arrays and you may
return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/

/*
************* Java Code **************

public int[] intersect(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int[] mp = new int[1001];
        for (int i = 0; i < n; i++)
        {
            mp[nums1[i]]++;
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < m; i++)
        {
            if (mp[nums2[i]] > 0)
            {
                ans.add(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }

*/