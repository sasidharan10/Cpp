#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> canSeePersonsCount2(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n, 0);
        if (n == 1)
            return ans;
        for (int i = n - 2; i >= 0; i--)
        {
            int persons = 1;
            while (!st.empty() && heights[i] > st.top())
            {
                persons++;
                st.pop();
            }
            ans[i] = persons;
            st.push(heights[i]);
        }
        return ans;
    }

    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);
        if (n == 1)
            return ans;
        st.push({heights[n - 1], 0});
        for (int i = n - 2; i >= 0; i--)
        {
            int persons = 1;
            while (!st.empty() && heights[i] > st.top().first)
            {
                persons+=st.top().second;
                st.pop();
            }
            ans[i] = persons;
            st.push({heights[i], persons});
        }
        return ans;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{5, 1, 2, 3, 10};
    // vector<int> nums{10, 6, 8, 5, 11, 9};
    vector<int> nums{4,3,2,1};
    vector<int> ans = s.canSeePersonsCount(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-visible-people-in-a-queue/

Youtube:

algorithm:

*/

/*

1944. Number of Visible People in a Queue

There are n people standing in a queue, and they numbered from 0 to n - 1
in left to right order. You are given an array heights of distinct integers
where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if
everybody in between is shorter than both of them. More formally,
the ith person can see the jth person if i < j and
min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number
of people the ith person can see to their right in the queue.

Example 1:

Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.
Example 2:

Input: heights = [5,1,2,3,10]
Output: [4,1,1,1,0]

*/