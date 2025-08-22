#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // LeetCode 168: Excel Sheet Column Title
    string convertToTitle(int columnNumber)
    {
        // TC: O(log₍26₎(n))   (dividing by 26 each step)
        // SC: O(1)            (output string not counted)

        string s;
        while (columnNumber > 0)
        {
            columnNumber--;              // adjust to 0-indexed
            int rem = columnNumber % 26; // remainder → character
            s += rem + 'A';              // map 0..25 → 'A'..'Z'
            columnNumber /= 26;          // move to next digit
        }
        reverse(s.begin(), s.end()); // reverse to get correct order
        return s;
    }
};
int main()
{
    Solution s;
    int n = 28;
    cout << "Result: " << s.convertToTitle(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/excel-sheet-column-title/

Youtube: https://www.youtube.com/watch?v=8QfC0elqK1o

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Mathematical/Excel%20Sheet%20Column%20Title.cpp

algorithm:

- Optimal Approach:

- Excel column is like base-26 number system, but 1-indexed.
- Subtract 1 to make it 0-indexed before taking remainder. Why?, below explained.
    - Excel columns are 1-indexed, not 0-indexed.
    - In base-26: normally digits go from 0..25.
    - In Excel: letters go from 1..26 → "A"=1, "B"=2, ..., "Z"=26.
    - This causes a mismatch:
    - Normally, remainder 0 means "A", but in Excel remainder 0 should mean "Z".
    - Example: columnNumber = 26 → we want "Z", not "@A".
    - Subtract 1 first → shifts the system to 0-indexed.
    - Now "A" corresponds to 0, "B" to 1, …, "Z" to 25.
    - Works perfectly with % 26.

- Remainder → map to 'A'..'Z'.
- Divide columnNumber by 26 to move left.
- Reverse result at the end since we build from rightmost character.
- Example: 28 → "AB" (28-1=27, rem=1 → 'B', next=1 → 'A').

*/

/*

168. Excel Sheet Column Title

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

Example 1:

Input: columnNumber = 1
Output: "A"

Example 2:

Input: columnNumber = 28
Output: "AB"

Example 3:

Input: columnNumber = 701
Output: "ZY"

Constraints:

1 <= columnNumber <= 2^31 - 1

*/

/*
************* Java Code **************

    public static String convertToTitle(int columnNumber) {
        StringBuilder sb = new StringBuilder();
        while (columnNumber > 0) {
            columnNumber--;
            int rem = columnNumber % 26;
            sb.append((char) (rem + 'A'));
            columnNumber /= 26;
        }
        sb.reverse();
        return sb.toString();
    }

*/