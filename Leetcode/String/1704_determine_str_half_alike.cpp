#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = s.length();
        int j = n / 2;
        int firstCount = 0, secondCount = 0;
        for (int i = 0; i < j; i++)
        {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                firstCount++;
        }
        for (int i = j; i < n; i++)
        {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                secondCount++;
        }
        return firstCount == secondCount;
    }
};
int main()
{
    Solution s;
    string str = "textbook";
    // string str = "book";
    cout << "String Halves Are Alike: " << s.halvesAreAlike(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/determine-if-string-halves-are-alike

Youtube:

algorithm:

*/

/*

1704. Determine if String Halves Are Alike

You are given a string s of even length. Split this string into two halves
of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels
('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s
contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel.
Therefore, they are alike.

Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2.
Therefore, they are not alike.
Notice that the vowel o is counted twice.

*/