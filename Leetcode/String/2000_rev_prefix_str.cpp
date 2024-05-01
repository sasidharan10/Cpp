#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int n = word.length();
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (word[i] == ch)
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return word;
        int i = 0;
        int j = idx;
        while (i < j)
        {
            swap(word[i], word[j]);
            i++;
            j--;
        }
        return word;
    }
};
int main()
{
    Solution s;
    string word = "abcdefd";
    char ch = 'd';
    cout << "Result: " << s.reversePrefix(word, ch) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reverse-prefix-of-word/

Youtube: https://www.youtube.com/watch?v=EH3EdJobbA8

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Easy%20Tagged/Reverse%20Prefix%20of%20Word.cpp

algorithm:

- Approach:

- no explanation needed.

*/

/*

2000. Reverse Prefix of Word

Given a 0-indexed string word and a character ch, reverse the segment of word
that starts at index 0 and ends at the index of the first occurrence of ch (inclusive).
If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment
that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".

Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".

Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".

*/

/*
************* Java Code **************

public static String reversePrefix(String word, char ch) {
        int n = word.length();
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (word.charAt(i) == ch) {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return word;
        int i = 0;
        int j = idx;
        char[] arr = word.toCharArray();
        while (i < j) {
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        return new String(arr);
    }

*/