#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Gives TLE
    string clearStars2(string s)
    {
        // TC: O(n*m) ~ O(n^2)
        // SC: O(n)

        int n = s.length();
        int i = 0;
        while (i < n)
        {
            if (s[i] == '*')
            {
                int ascii = (int)('z' + 1);
                int idx = -1;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (s[j] != '*' && (int)s[j] < ascii)
                    {
                        ascii = (int)s[j];
                        idx = j;
                    }
                }
                if (idx != -1)
                {
                    s[idx] = '*';
                }
            }
            i++;
        }
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*' || s[i] == '$')
                continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
    struct comp
    {
        bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
        {
            if (p1.first == p2.first)
            {
                return p1.second < p2.second;
            }
            else
                return p1.first > p2.first;
        }
    };
    // Better
    string clearStars(string s)
    {
        // TC: O(n*m) ~ O(n^2)
        // SC: O(n)

        int n = s.length();
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '*')
            {
                pq.push({s[i], i});
            }
            else
            {
                int idx = pq.top().second;
                s[idx] = '*';
                pq.pop();
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
                continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "abcde*f*";
    cout << "Result: " << s.clearStars(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars

Youtube: https://www.youtube.com/watch?v=-0xkQYTP1I0

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Heap/Lexicographically%20Minimum%20String%20After%20Removing%20Stars.cpp

algorithm:

- Brute Force Approach:

- self explanatory

- Optimal Approach:

- Using pq with custom sorting

*/

/*

3170. Lexicographically Minimum String After Removing Stars

You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
While there is a '*', do the following operation:
Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest
characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.

Example 1:

Input: s = "aaba*"
Output: "aab"

Explanation:
We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

Example 2:

Input: s = "abc"
Output: "abc"

Explanation:
There is no '*' in the string.

Constraints:

1 <= s.length <= 10^5
s consists only of lowercase English letters and '*'.
The input is generated such that it is possible to delete all '*' characters.

*/

/*
************* Java Code **************

    public static class Pair {
        private char first;
        private int second;

        public Pair(char first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public String clearStars(String s) {
        int n = s.length();
        Queue<Pair> pq = new PriorityQueue<>((a, b) -> {
            if (a.first == b.first) {
                return b.second - a.second;
            } else
                return Character.compare(a.first, b.first);
        });
        char[] charArray = s.toCharArray();
        for (int i = 0; i < n; i++) {
            if (charArray[i] != '*') {
                pq.offer(new Pair(charArray[i], i));
            } else {
                int idx = pq.peek().second;
                charArray[idx] = '*';
                pq.poll();
            }
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (charArray[i] == '*')
                continue;
            ans.append(charArray[i]);
        }
        return ans.toString();
    }

*/