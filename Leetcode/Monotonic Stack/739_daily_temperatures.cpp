#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    vector<int> dailyTemperatures2(vector<int> &temperatures)
    {
        // TC: O(n^2)
        // SC: O(1) or O(n) for storing ans

        int n = temperatures.size();
        if (n == 1)
            return {0};
        int j = 1;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (j < n && temperatures[i] >= temperatures[j])
            {
                j++;
            }
            if (j >= n)
                ans[i] = 0;
            else
                ans[i] = j - i;
            j = i + 2;
        }
        return ans;
    }

    // Optimal
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // TC: O(n)
        // SC: O(n) * 2

        int n = temperatures.size();
        if (n == 1)
            return {0};
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            if (st.empty())
                ans[i] = 0;
            else
                ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = s.dailyTemperatures(nums);
    cout << "No of days, to find warmer temperature: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/daily-temperatures

Youtube: https://www.youtube.com/watch?v=ZhZEmGv-sOY

algorithm:

- We use a monotonic stack(maintains increasing order) and store the indices of
  temperatures, which maintains a increasing order(as we pop each element, we
  get bigger numbers).
- We traverse from back, and check if cur element is greater than st.top().
  If yes, then we pop() elements from stack, until we find a greater
  element (i.e., st.top() > cur).
- If found, that means these is a greater element present in array, and its
  distance from cur element => (st.top() - cur_index).
- If no element found, stack becomes empty. hence there is no element greater than
  cur element, hence we assign 0.
- Once the check is done, we push the current element in stack and continue.

*/

/*

739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return
an array answer such that answer[i] is the number of days you have to wait
after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

*/
