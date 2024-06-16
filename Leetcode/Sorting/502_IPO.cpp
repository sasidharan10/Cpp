#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp.push_back({capital[i], profits[i]});
        }

        auto comparator = [&](pair<int, int> &p1, pair<int, int> &p2)
        {
            if (p1.first != p2.first)
                return p1.first < p2.first;
            else
                return p1.second > p2.second;
        };

        sort(mp.begin(), mp.end(), comparator);

        for (int i = 0; i < n; i++)
        {
            cout<<mp[i].first<<" : "<<mp[i].second<<endl;
        }
        

        int idx = 0;
        while (k > 0 && idx < n)
        {
            int cap = mp[idx].first;
            int pft = mp[idx].second;
            if (cap > w)
                return w;
            w += pft;
            idx++;
            k--;
        }
        return w;
    }
};
int main()
{
    Solution s;
    // vector<int> profits = {1, 2, 3}, capital = {0, 1, 2};
    // int k = 3, w = 0;
    vector<int> profits = {1, 2, 3}, capital = {1, 1, 2};
    int k = 1, w = 2;
    cout << "Result: " << s.findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/ipo/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

502. IPO

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares
to Venture Capital, LeetCode would like to work on some projects to increase its capital
before the IPO. Since it has limited resources, it can only finish at most k distinct
projects before the IPO. Help LeetCode design the best way to maximize its total
capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a
minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure
profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final
capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2
to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.

Example 2:

Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6

Constraints:

1 <= k <= 105
0 <= w <= 109
n == profits.length
n == capital.length
1 <= n <= 105
0 <= profits[i] <= 104
0 <= capital[i] <= 109

*/

/*
************* Java Code **************



*/