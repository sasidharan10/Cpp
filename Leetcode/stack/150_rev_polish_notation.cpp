#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                int num = stoi(tokens[i]);
                st.push(num);
            }
            else
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int res = 0;
                char ch = tokens[i][0];
                switch (ch)
                {
                case '+':
                    res = num1 + num2;
                    break;
                case '-':
                    res = num1 - num2;
                    break;
                case '/':
                    res = num1 / num2;
                    break;
                case '*':
                    res = num1 * num2;
                    break;
                default:
                    break;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};
int main()
{
    Solution s;
    vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Result: " << s.evalRPN(tokens) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/evaluate-reverse-polish-notation/

Youtube: https://www.youtube.com/watch?v=BM-bu4tJz7U

algorithm:

- Optimal Approach:

- We store all the operands in the stack.
- When we get any operators, we pop 2 operans from the stack
  and perform the operation, then again push the result in the stack.

*/

/*

150. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic
expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/