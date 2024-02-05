#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.length();
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++)
        {
            int idx = s[i] - 'a';
            mp[idx]++;
        }
        for (int i = 0; i < n; i++)
        {
            int idx = s[i] - 'a';
            if (mp[idx] == 1)
                return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    string str = "loveleetcode";
    cout << "Result: " << s.firstUniqChar(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/first-unique-character-in-a-string/

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

387. First Unique Character in a String

Given a string s, find the first non-repeating character in it and return
its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1

*/