#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        string res = "";
        int n1 = str1.length();
        int n2 = str2.length();
        string temp = "";
        for (int i = 0; i < n2; i++)
        {
            temp += str2[i];
            int j = 0;
            while (j<n1)
            {
                
            }
            
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