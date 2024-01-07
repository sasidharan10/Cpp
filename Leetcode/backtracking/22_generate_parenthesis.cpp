#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> res;
    void solve(int open, int close, int n, string temp)
    {
        // TC: O(n * 2^n)
        // SC: O(n) + RSS
        
        if (open == n && close == n)
        {
            res.push_back(temp);
            return;
        }
        else
        {
            if (open < n)
            {
                solve(open + 1, close, n, temp + "(");
            }
            if (open > close)
            {
                solve(open, close + 1, n, temp + ")");
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        solve(0, 0, n, "");
        return res;
    }
};
int main()
{
    Solution s;
    int n = 3;
    vector<string> ans = s.generateParenthesis(n);
    cout << "All Possible Parenthesis: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/generate-parentheses/

Youtube: https://www.youtube.com/watch?v=yBXTAfNuOQg

algorithm:

*/

/*

22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

*/