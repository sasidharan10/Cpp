#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        // TC: O(n) + O(26) ~ O(n)
        // SC: O(26) ~ O(1)
        
        int n = s.length();
        if (n < k)   // not possible
            return false;
        if(n == k)   // each single char is a palindrome itself.
            return true;
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++)
        {
            int ch = s[i] - 'a';
            mp[ch]++;
        }
        int oddFreq = 0;
        for (int i = 0; i < 26; i++)
        {
            if (mp[i] % 2 != 0)
            {
                oddFreq++;
            }
        }
        return (oddFreq > k) ? false : true;
    }
};
int main()
{
    Solution s;
    // string str = "annabelle";
    // int k = 2;
    // string str = "leetcode";
    // int k = 3;
    string str = "cr";
    int k = 7;
    cout << "Result: " << s.canConstruct(str, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/construct-k-palindrome-strings

Youtube: https://www.youtube.com/watch?v=Hh14hvVIHJc

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Construct%20K%20Palindrome%20Strings.cpp

algorithm:

- Optimal Approach:

- a palindrome can have only 1 element in odd frequency. hence count the no of odd freq elements
  and compare it with k.

*/

/*

1400. Construct K Palindrome Strings

Given a string s and an integer k, return true if you can use all the characters in s to construct k
palindrome strings or false otherwise.

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= 10^5

*/

/*
************* Java Code **************

    public static boolean canConstruct(String s, int k) {
        int n = s.length();
        if (n < k) // not possible
            return false;
        if (n == k) // each single char is a palindrome itself.
            return true;
        int[] mp = new int[26];
        for (int i = 0; i < n; i++) {
            int ch = s.charAt(i) - 'a';
            mp[ch]++;
        }
        int oddFreq = 0;
        for (int i = 0; i < 26; i++) {
            if (mp[i] % 2 != 0) {
                oddFreq++;
            }
        }
        return (oddFreq > k) ? false : true;
    }

*/