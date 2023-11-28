#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // TC: O(2n)
        // SC: O(2n)
        
        stack<int> st;
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        unordered_map<int, int> map;
        for (int i = m - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            if (st.empty())
                map.insert({nums2[i], -1});
            else
                map.insert({nums2[i], st.top()});
            st.push(nums2[i]);
        }
        for (auto &&i : nums1)
        {
            ans.push_back(map[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums1{4, 1, 2};
    vector<int> nums2{1, 3, 4, 2};
    vector<int> ans = s.nextGreaterElement(nums1, nums2);
    cout << "Next Greater Element Array: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/next-greater-element-i/description/

Youtube: https://www.youtube.com/watch?v=Du881K7Jtk8

algorithm:

- we basically, maintain a stack, where we keep the greater element
*/


/*

496. Next Greater Element I

The next greater element of some element x in an array is the first greater element 
that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, 
where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] 
and determine the next greater element of nums2[j] in nums2. If there is no next 
greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the 
next greater element as described above.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.


*/