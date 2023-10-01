#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        // TC: O(2n)
        // SC: O(n)

        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
                st.pop();
            if (!st.empty() && i < n)
                ans[i]=st.top();
            st.push(nums[i % n]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 3};
    vector<int> ans = s.nextGreaterElements(nums);
    cout << "Next Greater Element Array: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/next-greater-element-ii/

Youtube: https://www.youtube.com/watch?v=Du881K7Jtk8

algorithm:

*/