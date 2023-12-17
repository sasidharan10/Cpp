#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<string> generateParenthesis(int n) {
        
    }
};
int main()
{
    Solution s;
    int n = 3;
    vector<string> ans = s.generateParenthesis(n);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/generate-parentheses/

Youtube: 

algorithm: 

*/

/*

22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

*/