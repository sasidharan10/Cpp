#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        // TC: O(n + m)
        // SC: O(n + m)

        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int sum = 0, carry = 0;
        while (i >= 0 || j >= 0 || carry == 1)
        {
            sum += carry;
            if (i >= 0)
                sum += a[i] == '1' ? 1 : 0;
            if (j >= 0)
                sum += b[j] == '1' ? 1 : 0;
            res.append(to_string(sum % 2));
            carry = sum / 2;
            sum = 0;
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main()
{
    Solution s;
    string a = "1010", b = "1011";
    cout << "Result: " << s.addBinary(a, b) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/add-binary

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Set pointers i, j at ends of strings; carry = 0, res = "".
- Loop while digits remain or carry exists.
- Start each step with sum = carry.
- If i valid → add bit value of a[i].
- If j valid → add bit value of b[j].
- Now sum can be 0–3:
- sum % 2 → current result bit → append to res.
- sum / 2 → next carry.
- Move i--, j-- (shift left in binary).
- After loop → reverse res (built backwards).
- Return result.

*/

/*

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

*/

/*
************* Java Code **************

    public String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry == 1) {
            int sum = carry;
            if (i >= 0) sum += a.charAt(i--) - '0';
            if (j >= 0) sum += b.charAt(j--) - '0';

            result.append(sum % 2);
            carry = sum / 2;
        }

        return result.reverse().toString();
    }

*/