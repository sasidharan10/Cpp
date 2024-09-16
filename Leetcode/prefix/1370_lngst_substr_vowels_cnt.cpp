#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - using map of string
    int findTheLongestSubstring2(string s)
    {
        // TC: O(n)
        // SC: O(n)

        int n = s.length();
        unordered_map<string, int> mp;
        mp["00000"] = -1;
        int vowelsCount[5] = {0};
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            string currState = "";
            if (s[i] == 'a')
                vowelsCount[0] = (vowelsCount[0] + 1) % 2;
            else if (s[i] == 'e')
                vowelsCount[1] = (vowelsCount[1] + 1) % 2;
            else if (s[i] == 'i')
                vowelsCount[2] = (vowelsCount[2] + 1) % 2;
            else if (s[i] == 'o')
                vowelsCount[3] = (vowelsCount[3] + 1) % 2;
            else if (s[i] == 'u')
                vowelsCount[4] = (vowelsCount[4] + 1) % 2;

            for (int j = 0; j < 5; j++)
            {
                currState += to_string(vowelsCount[j]);
            }

            if (mp.find(currState) != mp.end())
                res = max(res, i - mp[currState]);
            else
                mp[currState] = i;
        }
        return res;
    }

    // Using bitmask.
    int findTheLongestSubstring(string s)
    {
        // TC: O(n)
        // SC: O(2^5) = O(32) ~= O(1)

        int n = s.length();
        unordered_map<int, int> mp;
        int mask = 0;
        mp[mask] = -1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int val = 0;
            if (s[i] == 'a')
                val = (1 << 0);
            else if (s[i] == 'e')
                val = (1 << 1);
            else if (s[i] == 'i')
                val = (1 << 2);
            else if (s[i] == 'o')
                val = (1 << 3);
            else if (s[i] == 'u')
                val = (1 << 4);

            mask = mask ^ val;

            if (mp.find(mask) != mp.end())
                res = max(res, i - mp[mask]);
            else
                mp[mask] = i;
        }
        return res;
    }
};
int main()
{
    Solution s;
    string str = "eleetminicoworoep";
    cout << "Result: " << s.findTheLongestSubstring(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts

Youtube: https://www.youtube.com/watch?v=6Xf5LfM-ciI

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Find%20the%20Longest%20Substring%20Containing%20Vowels%20in%20Even%20Counts.cpp

algorithm:

- Better Approach:

- The logic is, we store the vowels frequency, in a string, but we only need to know if 
  the frequency is odd or even, hence we calculate that and just store the result.
- We use a map, to store each of these results along with its index. 
- The string "currState" contains the result, after computing the frequency.
- We loop through the string, and check if we have already encountered these states, 
  then it means, from the current index 'i' to index mp[currstate], the subarray will have the
  state "00000" or in other words, the vowels present in that subarray has even frequency.
- We update the maxLen, to find the length of the max subarray and return it.

- Optimal Approach:

- Same logic, but instead of storing the results in a string, we use bitmask. 
- This approach saves more space
- refer LC 525, 560.

*/

/*

1371. Find the Longest Substring Containing Vowels in Even Counts

Given the string s, return the size of the longest substring containing each vowel an even number 
of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the 
vowels: e, i and o and zero of the vowels: a and u.

Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.

Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all 
vowels: a, e, i, o and u appear zero times.
 
Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.

*/

/*
************* Java Code **************

    public static int findTheLongestSubstring(String s) {
        int n = s.length();
        HashMap<Integer, Integer> mp = new HashMap<>();
        int mask = 0;
        mp.put(mask, -1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int val = 0;
            if (s.charAt(i) == 'a')
                val = (1 << 0);
            else if (s.charAt(i) == 'e')
                val = (1 << 1);
            else if (s.charAt(i) == 'i')
                val = (1 << 2);
            else if (s.charAt(i) == 'o')
                val = (1 << 3);
            else if (s.charAt(i) == 'u')
                val = (1 << 4);

            mask = mask ^ val;

            if (mp.containsKey(mask))
                res = Math.max(res, i - mp.get(mask));
            else
                mp.put(mask, i);
        }
        return res;
    }

*/