#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    string sortVowels2(string s)
    {
        string ans = "", vowels = "";
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                vowels += s[i];
            }
        }
        sort(vowels.begin(), vowels.end());
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                ans += vowels[j++];
            }
            else
                ans += s[i];
        }
        return ans;
    }
    // Optimal using count sort
    string sortVowels(string s)
    {
        unordered_map<char, int> mp;
        string ans = "", vowels = "AEIOUaeiou";
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                mp[s[i]]++;
            }
        }
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                while (!mp[vowels[j]])
                {
                    j++;
                }
                s[i] = vowels[j];
                mp[vowels[j]]--;
            }
        }
        return s;
    }
};
int main()
{
    Solution s;
    string str = "lEetcOde";
    cout << "String after sorting vowels: " << s.sortVowels(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sort-vowels-in-a-string

Youtube:

algorithm:

*/