#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        // TC: O(n) – traverse the string once
        // SC: O(7) ~ O(1) – fixed map for 7 Roman numerals

        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int res = 0; // result integer value

        for (int i = 0; i < s.length(); i++)
        {
            // If current value is less than next value, it's a subtractive pair (e.g., IV = 4)
            if ((i + 1 != s.length()) && (mp[s[i]] < mp[s[i + 1]]))
            {
                res -= mp[s[i]]; // subtract current value
            }
            else
            {
                res += mp[s[i]]; // otherwise, add current value
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    string str = "MCMXCIV";
    cout << "Roman to Integer: " << s.romanToInt(str);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/roman-to-integer/

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

13. Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII,
which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for
four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].

*/

/*
************* Java Code **************

    public static int romanToInt(String s) {
        char[] charArray = s.toCharArray();
        HashMap<Character, Integer> mp = new HashMap<>();
        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((i + 1 != s.length()) && (mp.get(charArray[i]) < mp.get(charArray[i + 1]))) {
                res -= mp.get(charArray[i]);
            } else
                res += mp.get(charArray[i]);
        }
        return res;
    }

*/