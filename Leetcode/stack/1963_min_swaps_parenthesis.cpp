#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Using stack
    int minSwaps3(string s)
    {
        // TC: O(n)
        // SC: O(n)

        stack<char> st;
        for (char &ch : s)
        {
            if (ch == '[')
                st.push(ch);
            else if (!st.empty())
                st.pop();
        }
        return (st.size() + 1) / 2;
    }

    // without stack - more readable
    int minSwaps2(string s)
    {
        // TC: O(n)
        // SC: O(1)

        int n = s.length();
        int opening = 0, closing = 0;
        int balanced = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[')
                opening++;
            else
                closing++;
            if (s[i] == ']' && opening > 0)
            {
                opening--;
                closing--;
                balanced++;
            }
        }
        int remaining = (n / 2) - balanced;
        return (remaining + 1) / 2;
    }

    // Optimal - without stack
    int minSwaps(string s)
    {
        // TC: O(n)
        // SC: O(1)

        int n = s.length();
        int size = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[')
                size++;
            else if (size > 0)
                size--;
        }
        return (size + 1) / 2;
    }
};
int main()
{
    Solution s;
    string str = "]]][[[";
    cout << "Result: " << s.minSwaps(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

Youtube: https://www.youtube.com/watch?v=W61jIP-O8lw

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Stack/Minimum%20Number%20of%20Swaps%20to%20Make%20the%20String%20Balanced.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

1963. Minimum Number of Swaps to Make the String Balanced

You are given a 0-indexed string s of even length n. The string consists of exactly n / 2
opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".

Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".

Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.

Constraints:

n == s.length
2 <= n <= 10^6
n is even.
s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.

*/

/*
************* Java Code **************

    public int minSwaps(String s) {
        int n = s.length();
        int size = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.charAt(i) == '[')
                size++;
            else if (size > 0)
                size--;
        }
        return (size + 1) / 2;
    }

*/