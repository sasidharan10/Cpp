#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
int main()
{
    Solution s;
    vector<char> nums{'H', 'a', 'n', 'n', 'a', 'h'};
    s.reverseString(nums);
    cout << "Result: " << endl;
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reverse-string/

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- using Two pointers and swapping until i and j cross each other.

*/

/*

344. Reverse String

Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.

*/

/*
************* Java Code **************

public void reverseString(char[] s) {
        int n = s.length;
        int i = 0, j = n - 1;
        while (i < j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }

*/