#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // using substring and sorting, then comparing.
    bool checkInclusion3(string s1, string s2)
    {
        // TC: O((m - n) * (nlogn))
        // SC: O(n)

        int n = s1.size();
        int m = s2.size();

        sort(s1.begin(), s1.end());
        for (int i = 0; i <= m - n; i++)
        {
            string temp = s2.substr(i, n);
            sort(temp.begin(), temp.end());
            if (s1 == temp)
                return true;
        }
        return false;
    }

    // using array[26] as map and comparing the frequency.
    bool checkInclusion(string s1, string s2)
    {
        // TC: O(m)
        // SC: O(n)

        int n = s1.size();
        int m = s2.size();

        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        for (int i = 0; i < n; i++)
        {
            mp1[s1[i] - 'a']++;
        }
        int i = 0, j = 0;
        while (j < m)
        {
            mp2[s2[j] - 'a']++;
            // Check if the current window size matches the size of s1
            if (j - i + 1 > n)
            {
                mp2[s2[i] - 'a']--;
                i++;
            }
            if (mp1 == mp2)
                return true;
            j++;
        }
        return false;
    }
};
int main()
{
    Solution s;
    string s1 = "ab", s2 = "eidbaooo";
    cout << "Result: " << s.checkInclusion(s1, s2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/permutation-in-string

Youtube: https://www.youtube.com/watch?v=iTwwvsyUsi4

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Permutation%20in%20String.cpp

algorithm:

- Brute Force Approach:

- check this video to implement all permutation
- https://www.youtube.com/watch?v=T8hqjK94Fig&t=0s

- Better:

- Use sliding window to get each substring, then sort it, then compare it with s1.

- Optimal Approach:

- Using array[26] as map.
- Note: bitmask wont work here, as frequency of each character be more than 1. In bitmask, 
  we cannot store the frequency of each character.


*/

/*

567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a
permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:

1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.

*/

/*
************* Java Code **************



*/