#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Monotonic stack - maintaining a increasing order
    string removeKdigits(string num, int k)
    {
        // TC: O(2n)
        // SC: O(n)

        int n = num.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            // popping elements, if increasing order not maintained
            while (!st.empty() && st.top() > num[i] && k > 0)
            {
                st.pop();
                k--;
            }
            // if first digit is 0, we ignore it
            if (!st.empty() || num[i] != '0')
                st.push(num[i]);
        }

        // Removing remaining k element elements
        while (!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }

        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        // return '0' if empty
        if (res == "")
            return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};
int main()
{
    Solution s;
    string num = "1432219";
    int k = 3;
    cout << "Result: " << s.removeKdigits(num, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/remove-k-digits/

Youtube: https://www.youtube.com/watch?v=lWcZB7l-O7M

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Stack/Remove%20K%20Digits.cpp

algorithm:

- Approach:

- To get the smallest number, we need to make the digits to be in increasing order.
- We cannot make the num to be strictly inceasing, but we try as much as possible by popping k elements.
- If we popped k elements, then the remaning elements will be left as it is.
- We use monotonic stack to maintain the increasing order in the stack, by popping exactly k elements.
- if first digit is 0, we should ignore it.
- If the input is already in increasing order, then we just pop remaining k elements
  from the stack.
- Finally we return the result.

*/

/*

402. Remove K Digits

Given string num representing a non-negative integer num, and an integer k, return the
smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not
contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/

/*
************* Java Code **************

public static String removeKdigits(String num, int k) {
        int n = num.length();
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            // popping elements, if increasing order not maintained
            while (!st.isEmpty() && st.peek() > num.charAt(i) && k > 0) {
                st.pop();
                k--;
            }
            // if first digit is 0, we ignore it
            if (!st.isEmpty() || num.charAt(i) != '0')
                st.push(num.charAt(i));
        }

        // Removing remaining k element elements
        while (!st.isEmpty() && k > 0) {
            st.pop();
            k--;
        }

        StringBuilder res = new StringBuilder();
        while (!st.isEmpty()) {
            res.append(st.pop());
        }

        // return '0' if empty
        if (res.isEmpty())
            return "0";
        res.reverse();
        return res.toString();
    }

*/