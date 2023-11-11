#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> wordLadderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // TC: Not possible to calcualte
        // SC: O(n)

        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        while (!q.empty())
        {
            vector<string> usedString;
            int n = q.size();
            while (n > 0)
            {
                vector<string> vec = q.front();
                q.pop();
                if (vec.back() == endWord)
                {
                    if (ans.size() == 0 || vec.size() == ans[0].size())
                        ans.push_back(vec);
                }
                string word = vec.back();
                for (int i = 0; i < word.length(); i++)
                {
                    char original = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[i] = ch;
                        if (st.find(word) != st.end())
                        {
                            vec.push_back(word);
                            q.push(vec);
                            vec.pop_back();
                            usedString.push_back(word);
                        }
                    }
                    word[i] = original;
                }
                n--;
            }
            for (auto &&i : usedString)
            {
                st.erase(i);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> wordList{"des", "der", "dfr", "dgt", "dfs"};
    string beginWord = "der", endWord = "dfs";
    cout << "All possible smallest transformation sequence from beginWord to endWord : " << endl;
    vector<vector<string>> ans = s.wordLadderLength(beginWord, endWord, wordList);
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

leetcode: https://leetcode.com/problems/word-ladder-ii/

Youtube: https://www.youtube.com/watch?v=DREutrv2XD0&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=30

algorithm:

*/