#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        // using ACSII addition
        // TC: O(2n)
        // SC: O(1)
        int a = 0, b = 0;
        for (int i = 0; i < s.length(); i++)
        {
            a += (int)s[i];
        }
        for (int i = 0; i < t.length(); i++)
        {
            b += (int)t[i];
        }
        return (char)(b - a);
    }
    char findTheDifference1(string s, string t)
    {
        // using XOR
        // TC: O(2n)
        // SC: O(1)
        
        char c = 0;
        for (int i = 0; i < s.length(); i++)
        {
            c ^= s[i];
        }
        for (int i = 0; i < t.length(); i++)
        {
            c ^= t[i];
        }
        return c;
    }
};
int main()
{
    Solution s;
    string a = "abcd", b = "abcde";
    // cout << "Difference: " << s.findTheDifference(a, b);
    cout << "Difference: " << s.findTheDifference1(a, b);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-difference/

Youtube: https://www.youtube.com/watch?v=JyA858J7CrA

algorithm:

- Sort both string, then traverse through to find the odd element
- store the chars in map, then find the odd element

*/