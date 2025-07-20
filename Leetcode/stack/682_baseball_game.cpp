#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // better
    int calPoints2(vector<string> &operations)
    {
        // TC: O(2n) ~ O(n)
        // SC: O(n)
        
        int n = operations.size();
        stack<string> st;
        for (int i = 0; i < n; i++)
        {
            if (operations[i] == "C")
                st.pop();
            else if (operations[i] == "D")
            {
                string temp = st.top();
                int num = stoi(temp);
                num *= 2;
                temp = to_string(num);
                st.push(temp);
            }
            else if (operations[i] == "+")
            {
                string temp1 = st.top();
                st.pop();
                string temp2 = st.top();
                st.pop();
                int num1 = stoi(temp1);
                int num2 = stoi(temp2);
                st.push(temp2);
                st.push(temp1);
                int res = num1 + num2;
                temp1 = to_string(res);
                st.push(temp1);
            }
            else
                st.push(operations[i]);
        }
        int res = 0;
        while (!st.empty())
        {
            string temp = st.top();
            st.pop();
            int num = stoi(temp);
            res += num;
        }
        return res;
    }

    // Optimal
    int calPoints(vector<string> &operations)
    {
        // TC: O(n)
        // SC: O(n)

        int n = operations.size();
        stack<int> st;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (operations[i] == "C")
            {
                res -= st.top();
                st.pop();
            }
            else if (operations[i] == "D")
            {
                st.push(st.top() * 2);
                res += st.top();
            }
            else if (operations[i] == "+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2);
                st.push(num1);
                st.push(num1 + num2);
                res += st.top();
            }
            else
            {
                st.push(stoi(operations[i]));
                res += st.top();
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<string> nums{"5", "-2", "4", "C", "D", "9", "+", "+"};
    cout << "Result: " << s.calPoints(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/baseball-game/

Youtube: https://www.youtube.com/watch?v=Id_tqGdsZQI

Code Link:

algorithm:

- Optimal Approach:

- use stack

*/

/*

682. Baseball Game

You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you 
start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply 
to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit 
integer and that all operations are valid.

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.

Example 3:

Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.
 
Constraints:

1 <= operations.length <= 1000
operations[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 10^4, 3 * 10^4].
For operation "+", there will always be at least two previous scores on the record.
For operations "C" and "D", there will always be at least one previous score on the record.


*/

/*
************* Java Code **************

    public int calPoints(String[] ops) {
        int res = 0;
        Stack<Integer> stack = new Stack<>();
        for (String op : ops) {
            if (op.equals("+")) {
                int top = stack.pop();
                int newTop = top + stack.peek();
                stack.push(top);
                stack.push(newTop);
                res += newTop;
            } else if (op.equals("D")) {
                stack.push(2 * stack.peek());
                res += stack.peek();
            } else if (op.equals("C")) {
                res -= stack.pop();
            } else {
                stack.push(Integer.parseInt(op));
                res += stack.peek();
            }
        }
        return res;
    }

*/