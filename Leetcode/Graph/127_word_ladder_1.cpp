#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // TC: O(n * wordLength * 26)
        // SC: O(n)

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endWord)
                return steps;
            for (int i = 0; i < word.length(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
int main()
{
    Solution s;
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit", endWord = "cog";
    cout << "The length of the smallest transformation sequence from beginWord to endWord : ";
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/word-ladder/1

leetcode: https://leetcode.com/problems/word-ladder/

Youtube: https://www.youtube.com/watch?v=tRPda0rcf8E&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=29

algorithm:

*/