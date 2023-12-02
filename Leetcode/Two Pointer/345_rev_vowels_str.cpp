#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        else
            return false;
    }
    // Brute
    string reverseVowels2(string s)
    {
        string temp = "";
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                temp += s[i];
            }
        }
        reverse(temp.begin(), temp.end());
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                s[i] = temp[j++];
            }
        }
        return s;
    }
    // Optimal - two pointer
    string reverseVowels(string s)
    {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j)
        {
            while (!isVowel(s[i]) && i < j)
            {
                i++;
            }
            while (!isVowel(s[j]) && i < j)
            {
                j--;
            }
            if (i >= j)
                break;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};
int main()
{
    Solution s;
    string str = "leetcode";
    cout << "Reverse Vowels of a String: " << s.reverseVowels(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reverse-vowels-of-a-string

Youtube:

algorithm:

- use Two pointer

*/

/*

345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower
and upper cases, more than once.


Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"


*/