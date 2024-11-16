#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(bool res, bool operand, char opr)
    {
        if (opr == '&')
            return res & operand;
        else if (opr == '|')
            return res | operand;
        else
            return !res;
        return res;
    }
    bool parseBoolExpr(string expression)
    {
        int n = expression.length();
        bool res;
        bool first = false;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (expression[i] == '(')
                continue;
            else if (expression[i] == '&' || expression[i] == '|' || expression[i] == '!')
                st.push(expression[i]);
            else if (expression[i] == ')')
                st.pop();
            else if (expression[i] == ',')
                continue;
            else if (expression[i] == 't' || expression[i] == 'f')
            {
                bool operand = (expression[i] == 't') ? true : false;
                if (!first)
                {
                    res = operand;
                    first = true;
                }
                if (!st.empty())
                {
                    res = solve(res, operand, st.top());
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    // string str = "&(|(f))";
    string str = "|(f,f,f,t)";
    cout << "Result: " << s.parseBoolExpr(str) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

1106. Parsing A Boolean Expression

A boolean expression is an expression that evaluates to either true or false. It can be in one of
the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions
subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions
subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation:
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.

Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.

Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation:
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.

Constraints:

1 <= expression.length <= 2 * 104
expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.

*/

/*
************* Java Code **************



*/