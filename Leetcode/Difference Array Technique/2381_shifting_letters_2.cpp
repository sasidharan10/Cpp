#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - gives TLE
    string shiftingLetters2(string s, vector<vector<int>> &shifts)
    {
        // TC: O(n*sz)
        // SC: O(n)

        int n = s.length();
        vector<int> mp(n, 0);
        for (int i = 0; i < n; i++)
        {
            mp[i] = s[i] - 'a';
        }

        int sz = shifts.size();
        for (int i = 0; i < sz; i++)
        {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];
            for (int j = start; j <= end; j++)
            {
                if (direction == 1)
                {
                    mp[j] = ((mp[j] + 1) == 26) ? 0 : (mp[j] + 1);
                }
                else
                {
                    mp[j] = ((mp[j] - 1) == -1) ? 25 : (mp[j] - 1);
                }
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            char ch = mp[i] + 97;
            ans += ch;
        }
        return ans;
    }

    // Optimal - difference array technique.
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        // TC: O(n + sz) ~ O(n)
        // SC: O(n)

        int n = s.length();
        vector<int> mp(n, 0);
        int sz = shifts.size();
        for (int i = 0; i < sz; i++)
        {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];
            if (direction == 1)
            {
                mp[start] = mp[start] + 1;
                if (end + 1 < n)
                    mp[end + 1] = mp[end + 1] - 1;
            }
            else
            {
                mp[start] = mp[start] - 1;
                if (end + 1 < n)
                    mp[end + 1] = mp[end + 1] + 1;
            }
        }
        // now taking cumulative sum:
        for (int i = 1; i < n; i++)
        {
            mp[i] = mp[i - 1] + mp[i];
        }
        
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            int shift = ((mp[i] % 26) + 26) % 26;
            // adding the shift to ith char
            int newPosition = (s[i] - 'a' + shift) %26;
            // convert to char
            char ch = newPosition + 97;
            ans += ch;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    cout << "Result: " << s.shiftingLetters(str, shifts) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/shifting-letters-ii

Youtube: https://www.youtube.com/watch?v=ZHNVmtm08WY

Code Link:

algorithm:

- Brute Force Approach:

- Just simulate the given problem.
- TC: O(n^2) - gives TLE

- Optimal Approach:

- self explanatory

*/

/*

2381. Shifting Letters II

You are given a string s of lowercase English letters and a 2D integer array shifts where
shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti
to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so
that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous
letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

Example 1:

Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
Example 2:

Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".

Constraints:

1 <= s.length, shifts.length <= 5 * 10^4
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s consists of lowercase English letters.

*/

/*
************* Java Code **************

    public static String shiftingLetters(String s, int[][] shifts) {

        int n = s.length();
        int[] mp = new int[n];
        int sz = shifts.length;
        for (int i = 0; i < sz; i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];
            if (direction == 1) {
                mp[start] = mp[start] + 1;
                if (end + 1 < n)
                    mp[end + 1] = mp[end + 1] - 1;
            } else {
                mp[start] = mp[start] - 1;
                if (end + 1 < n)
                    mp[end + 1] = mp[end + 1] + 1;
            }
        }
        // now taking cumulative sum:
        for (int i = 1; i < n; i++) {
            mp[i] = mp[i - 1] + mp[i];
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int shift = ((mp[i] % 26) + 26) % 26;
            // adding the shift to ith char
            int newPosition = ((s.charAt(i) - 'a') + shift) % 26;
            // convert to char
            char ch = (char) (newPosition + 97);
            ans.append(ch);
        }
        return ans.toString();
    }

*/