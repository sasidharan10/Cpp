#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // using map
    string customSortString2(string order, string s)
    {
        // TC: O(m + n)
        // SC: O(26)

        int n = order.length();
        int m = s.length();

        vector<int> mp(26, 0);
        for (int i = 0; i < m; i++)
        {
            mp[s[i] - 'a']++;
        }
        string res = "";
        for (int i = 0; i < n; i++)
        {
            int ch = order[i] - 'a';
            if (mp[ch] > 0)
            {
                char tp = ch + 'a';
                string temp = string(mp[ch], tp);
                res += temp;
                mp[ch] = 0;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (mp[i] > 0)
            {
                char tp = i + 'a';
                string temp = string(mp[i], tp);
                res += temp;
            }
        }
        return res;
    }

    string customSortString(string order, string s)
    {
        // TC: O(nlogn)
        // SC: O(n)
        
        int n = order.length();
        int m = s.length();
        vector<int> mp;
        mp.resize(26, -1);
        for (int i = 0; i < n; i++)
        {
            mp[order[i] - 'a'] = i;
        }

        auto cmp = [&mp](char &ch1, char &ch2)
        {
            return mp[ch1 - 'a'] < mp[ch2 - 'a'];
        };

        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
int main()
{
    Solution s;
    string order = "bcafg", str = "abcd";
    cout << "Result: " << s.customSortString(order, str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/custom-sort-string/

Youtube: https://www.youtube.com/watch?v=oGPfmp71Zm4

algorithm:

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashMap/Custom%20Sort%20String.cpp

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

791. Custom Sort String

You are given two strings order and s. All the characters of order are
unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was
sorted. More specifically, if a character x occurs before a character y
in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

Example 1:

Input:  order = "cba", s = "abcd"

Output:  "cbad"

Explanation: "a", "b", "c" appear in order, so the order of
"a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in order, it can be at any position
in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input:  order = "bcafg", s = "abcd"

Output:  "bcad"

Explanation: The characters "b", "c", and "a" from order dictate the
order for the characters in s. The character "d" in s does not
appear in order, so its position is flexible.

Following the order of appearance in order, "b", "c", and "a" from s
should be arranged as "b", "c", "a". "d" can be placed at any position
since it's not in order. The output "bcad" correctly follows this rule.
Other arrangements like "bacd" or "bcda" would also be valid, as
long as "b", "c", "a" maintain their order.

*/

/*

public static String customSortString(String order, String s) {
        int n = order.length();
        int m = s.length();

        int[] mp = new int[26];
        for (int i = 0; i < m; i++) {
            mp[s.charAt(i) - 'a']++;
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int ch = order.charAt(i) - 'a';
            char tp = order.charAt(i);
            if (mp[ch] > 0) {
                while (mp[ch]-- > 0) {
                    res.append(tp);
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (mp[i] > 0) {
                char tp = (char) (i + 'a');
                while (mp[i]-- > 0) {
                    res.append(tp);
                }
            }
        }
        return res.toString();
    }


public static String customSortString(String order, String s) {
        Integer[] index = new Integer[26];
        Arrays.fill(index, -1);

        // Map characters to their positions in 'order'
        for (int i = 0; i < order.length(); i++)
            index[order.charAt(i) - 'a'] = i;

        Comparator<Character> lambda = (ch1, ch2) -> index[ch1 - 'a'].compareTo(index[ch2 - 'a']);

        Character[] charArray = new Character[s.length()];
        for (int i = 0; i < s.length(); i++) {
            charArray[i] = s.charAt(i);
        }

        Arrays.sort(charArray, lambda);

        // Convert Character array back to String
        StringBuilder result = new StringBuilder(charArray.length);
        for (char ch : charArray) {
            result.append(ch);
        }

        return result.toString();
    }    

*/