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

*/