#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else
            return false;
    }
    int maxVowels(string s, int k)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = s.length();
        int maxi = INT_MIN;
        int vowelsCount = 0;
        for (int i = 0; i < k; i++)
        {
            if (isVowel(s[i]))
                vowelsCount++;
        }
        int i = 0, j = k - 1;
        while (j < n)
        {
            maxi = max(maxi, vowelsCount);
            if (maxi == k)
                return maxi;
            if (isVowel(s[i]) && vowelsCount > 0)
                vowelsCount--;
            if (j + 1 < n && isVowel(s[j + 1]))
                vowelsCount++;
            i++;
            j++;
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    string str = "abciiidef";
    int k = 3;
    cout << "Maximum Number of Vowels in a Substring of Given Length: ";
    cout << s.maxVowels(str, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

Youtube:

algorithm:

- Sliding window

*/

/*

1456. Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k, return the maximum number of vowel
letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.



*/