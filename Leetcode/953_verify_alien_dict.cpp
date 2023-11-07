#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        // TC: O(n^2)
        // SC: O(26)
        
        unordered_map<int, int> mp;
        for (int i = 0; i < 26; i++)
        {
            mp.insert({order[i] - 'a', i});
        }
        for (int i = 0; i < words.size() - 1; i++)
        {
            string s1 = words[i];
            string s2 = words[i + 1];
            // "apple" , "app" test case
            if (s1.length() > s2.length() && s1.substr(0, s2.length()) == s2)
                return false;
            int len = min(s1.length(), s2.length());
            for (int ptr = 0; ptr < len; ptr++)
            {
                int first = mp[s1[ptr] - 'a'];
                int second = mp[s2[ptr] - 'a'];
                if (first == second)
                {
                    continue;
                }
                else if (first < second)
                {
                    break;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    // vector<string> words{"hello", "leetcode"};
    // string order = "hlabcdefgijkmnopqrstuvwxyz";
    vector<string> words{"word", "world", "row"};
    string order = "worldabcefghijkmnpqstuvxyz";
    cout << "Is it Lexicographically sorted?: " << s.isAlienSorted(words, order);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/verifying-an-alien-dictionary/description/

Youtube:

algorithm:

*/