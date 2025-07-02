#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int possibleStringCount(string word)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = word.length();
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (word[i] == word[i - 1])
                cnt++;
        }
        return cnt + 1; // count the given word itself.
    }
};
int main()
{
    Solution s;
    string word = "abbcccc";
    cout << "Result: " << s.possibleStringCount(word) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-original-typed-string-i

Youtube: https://www.youtube.com/watch?v=XpRSv1EFmhU

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Easy%20Tagged/Find%20the%20Original%20Typed%20String%20I.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

3330. Find the Original Typed String I

Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may
press a key for too long, resulting in a character being typed multiple times.
Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
You are given a string word, which represents the final output displayed on Alice's screen.
Return the total number of possible original strings that Alice might have intended to type.

Example 1:

Input: word = "abbcccc"
Output: 5

Explanation:

The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".

Example 2:

Input: word = "abcd"
Output: 1

Explanation:
The only possible string is "abcd".

Example 3:

Input: word = "aaaa"
Output: 4


Constraints:

1 <= word.length <= 100
word consists only of lowercase English letters.


*/

/*
************* Java Code **************

    public int possibleStringCount(String word) {
        int n = word.length();
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (word.charAt(i) == word.charAt(i - 1))
                cnt++;
        }
        return cnt + 1;
    }

*/