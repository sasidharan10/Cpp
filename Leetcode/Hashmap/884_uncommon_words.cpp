#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        // TC: O(n1 + n2)
        // SC: O(n1 + n2)
        
        int n1 = s1.length();
        int n2 = s2.length();
        unordered_map<string, int> mp;
        int i = 0, j = 0;
        while (j < n1)
        {
            while (j < n1 && s1[j] != ' ')
            {
                j++;
            }
            mp[(s1.substr(i, j - i))]++;
            j++;
            i = j;
        }
        i = 0, j = 0;
        while (j < n2)
        {
            while (j < n2 && s2[j] != ' ')
            {
                j++;
            }
            mp[(s2.substr(i, j - i))]++;
            j++;
            i = j;
        }
        vector<string> res;
        for (auto it : mp)
        {
            if (it.second == 1)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    string s1 = "this apple is sweet", s2 = "this apple is sour";
    vector<string> ans = s.uncommonFromSentences(s1, s2);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/uncommon-words-from-two-sentences

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Split the words and store its frequency using a map.
- Do this for both the sentences.
- Then, iterate through the map, and add the words to the resultant array, whose frequency is 1.
- Return the array.

*/

/*

884. Uncommon Words from Two Sentences

A sentence is a string of single-space separated words where each word consists only of lowercase letters.
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the
other sentence.
Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer
in any order.

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.

*/

/*
************* Java Code **************

    public static String[] uncommonFromSentences(String s1, String s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        HashMap<String, Integer> mp = new HashMap<>();
        int i = 0, j = 0;
        while (j < n1) {
            while (j < n1 && s1.charAt(j) != ' ') {
                j++;
            }
            String temp = s1.substring(i, j);
            mp.put(temp, mp.getOrDefault(temp, 0) + 1);
            j++;
            i = j;
        }
        i = 0;
        j = 0;
        while (j < n2) {
            while (j < n2 && s2.charAt(j) != ' ') {
                j++;
            }
            String temp = s2.substring(i, j);
            mp.put(temp, mp.getOrDefault(temp, 0) + 1);
            j++;
            i = j;
        }
        List<String> lt = new ArrayList<>();
        for (Map.Entry<String, Integer> it : mp.entrySet()) {
            if (it.getValue() == 1) {
                lt.add(it.getKey());
            }
        }
        String[] res = new String[lt.size()];
        for (int k = 0; k < lt.size(); k++) {
            res[k] = lt.get(k);
        }
        return res;
    }

*/