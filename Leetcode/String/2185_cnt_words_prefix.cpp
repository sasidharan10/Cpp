#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int prefixCount(vector<string>& words, string pref) {
        // TC: O(n*m), where m = len of pref
        // SC: O(1)
        
        int n = words.size();
        int len1 = pref.length();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int len2 = words[i].length();
            if(len1 > len2)
                continue;
            bool flag = true;
            for (int j = 0; j < len1; j++)
            {
                if(words[i][j] != pref[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt++;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<string> words{"pay","attention","practice","attend"};
    string pref = "at";
    cout << "Result: " <<s.prefixCount(words, pref)<< endl;
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/counting-words-with-a-given-prefix

Youtube: 

Code Link: 

algorithm: 

- Brute Force Approach:

- 

- Optimal Approach:

- Using trie, incomplete

*/

/*

2185. Counting Words With a Given Prefix

You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
 
Constraints:

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.

*/

/*   
************* Java Code **************



*/