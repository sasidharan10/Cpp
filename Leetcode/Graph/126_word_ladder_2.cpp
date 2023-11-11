#include <bits/stdc++.h>
using namespace std;
class Solution
{
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    int sz;
    void dfs(string word, vector<string> &seq)
    {
        int steps = mp[word];
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        for (int i = 0; i < sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    // Optimal, back-tracking
    vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string> &wordList)
    {
        // TC: Not possible to calcualte
        // SC: O(n)

        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        sz = beginWord.size();
        b = beginWord;
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front();
            int steps = mp[word];
            q.pop();
            if (word == endWord)
                break;
            for (int i = 0; i < sz; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        q.push(word);
                        mp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
    // Better, enough for interviews
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
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
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit", endWord = "cog";
    cout << "All possible smallest transformation sequence from beginWord to endWord : " << endl;
    vector<vector<string>> ans = s.findLadders2(beginWord, endWord, wordList);
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