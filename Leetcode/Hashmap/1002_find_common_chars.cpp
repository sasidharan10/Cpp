#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void fillCount(string &str, int temp[])
    {
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            temp[str[i] - 'a']++;
        }
    }
    vector<string> commonChars(vector<string> &words)
    {
        // TC: O(n * k) k = avg length of words[i]
        // SC: O(26)
        
        int n = words.size();
        vector<string> result;
        int count[26] = {0};
        fillCount(words[0], count);
        for (int i = 1; i < n; i++)
        {
            int temp[26] = {0};
            fillCount(words[i], temp);
            for (int j = 0; j < 26; j++)
            {
                count[j] = min(count[j], temp[j]);
            }
        }
        for (int i = 0; i < 26; i++)
        {
            int c = count[i];
            while (c--)
            {
                result.push_back(string(1, i + 'a'));
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<string> nums{"bella", "label", "roller"};
    vector<string> ans = s.commonChars(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-common-characters/

Youtube: https://www.youtube.com/watch?v=0sMVPGsY84w

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Find%20Common%20Characters.cpp

algorithm:

- Optimal Approach:

- Using 2 maps.

*/

/*

1002. Find Common Characters

Given a string array words, return an array of all characters that show up in all
strings within the words (including duplicates). You may return the answer in any order.

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.

*/

/*
************* Java Code **************

public static void fillCount(String str, int[] temp) {
        int n = str.length();
        for (int i = 0; i < n; i++) {
            temp[str.charAt(i) - 'a']++;
        }
    }

    public static List<String> commonChars(String[] words) {
        int n = words.length;
        List<String> result = new ArrayList<>();
        int[] count = new int[26];
        fillCount(words[0], count);
        for (int i = 1; i < n; i++) {
            int[] temp = new int[26];
            fillCount(words[i], temp);
            for (int j = 0; j < 26; j++) {
                count[j] = Math.min(count[j], temp[j]);
            }
        }
        for (int i = 0; i < 26; i++) {
            int c = count[i];
            while (c > 0) {
                result.add(String.valueOf((char) (i + 'a')));
                c--;
            }
        }
        return result;
    }

*/