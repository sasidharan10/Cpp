#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        int n1 = words1.size();
        int n2 = words2.size();
        vector<int> mp1(26, 0);
        for (int i = 0; i < n2; i++)
        {
            int m = words2[i].length();
            for (int j = 0; j < m; j++)
            {
                int ch = words2[i][j] - 'a';
                mp1[ch]++;
            }
        }
        vector<string> res;
        for (int i = 0; i < n1; i++)
        {
            vector<int> mp2(26, 0);
            int m = words1[i].length();
            for (int j = 0; j < m; j++)
            {
                int ch = words1[i][j] - 'a';
                mp2[ch]++;
            }
            bool flag = true;
            for (int j = 0; j < 26; j++)
            {
                if (mp1[j] > 0 && mp1[j] != mp2[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.push_back(words1[i]);
            // if (mp1 == mp2)
            //     res.push_back(words1[i]);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<string> words1{"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2{"e", "o"};
    vector<string> ans = s.wordSubsets(words1, words2);
    cout << "Result: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/word-subsets

Youtube: https://www.youtube.com/watch?v=EjXPzWYbviw

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*






*/

/*
************* Java Code **************



*/