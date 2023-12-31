#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    int maxLengthBetweenEqualCharacters2(string s)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = s.length();
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                    maxi = max(maxi, j - i - 1);
            }
        }
        return maxi;
    }
    // Optimal
    int maxLengthBetweenEqualCharacters(string s)
    {
        // TC: O(n)
        // SC: O(26) ~ O(1)

        int n = s.length();
        int maxi = -1;
        int mp[26];
        memset(mp, -1, sizeof(mp));
        for (int i = 0; i < n; i++)
        {
            int char_idx = s[i] - 'a';
            if (mp[char_idx] == -1)
            {
                mp[char_idx] = i;
            }
            else
            {
                maxi = max(maxi, i - mp[char_idx] - 1);
            }
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    // string str = "abca";
    string str = "mgntdygtxrvxjnwksqhxuxtrv";
    cout << "Result: " << s.maxLengthBetweenEqualCharacters(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/largest-substring-between-two-equal-characters

Youtube: https://www.youtube.com/watch?v=kQLhWLVlzYo

algorithm:

- Optimal Approach:

- We store the characters first index in thr map.
- check if the char is already stored in the map, if not, then store it.
- If yes, then take that chars first index, and take current index as the last
  index, calculate its distance, and update maxi.

*/

/*






*/