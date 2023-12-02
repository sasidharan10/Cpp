#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    string gcdOfStrings(string str1, string str2)
    {
        int n1 = str1.length();
        int n2 = str2.length();
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }
        else
        {
            return str1.substr(0, gcd(n1, n2));
        }
    }
};
int main()
{
    Solution s;
    string str1 = "ABCABC", str2 = "ABC";
    cout << "Greatest Common Divisor of Strings: " << s.gcdOfStrings(str1, str2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/greatest-common-divisor-of-strings

Youtube:

algorithm:

Suppose str1 = "ABCABC" and str2 = "ABC"
str1 + str2 = ABCABCABC
str2 + str1 = ABCABCABC
str1 + str2 == str2 + str1
return str.substr(0, gcd(size(str1), gcd(size(str2))))
where gcd(3, 6) = 3
So, answer is "ABC"

Also str1 = "LEET", str2 = "CODE"
str1 + str2 = "LEETCODE"
str2 + str1 = "CODELEET"
str1 + str2 != str2 + str1
So, return ""


*/

/*

1071. Greatest Common Divisor of Strings

For two strings s and t, we say "t divides s" if and only if s = t + ... + t
(i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x
such that x divides both str1 and str2.

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""

*/