#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag = false;

    bool containKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        int n = word.length();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkCompleteString(string word)
    {
        int n = word.length();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (node->containKey(word[i]))
            {
                node = node->get(word[i]);
                if (node->isEnd() == false)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};

class Solution
{
public:
    // Optimal (using trie)
    string longestWord(vector<string> &words)
    {
        // TC: O(n) * O(len) len = length of string
        // SC: not defined
        
        Trie t;
        for (auto &&it : words)
        {
            t.insert(it);
        }
        string longest = "";
        for (auto &&it : words)
        {
            if (t.checkCompleteString(it))
            {
                if (it.length() > longest.length())
                    longest = it;
                else if (it.length() == longest.length() && it < longest)
                    longest = it;
            }
        }
        return longest;
    }

    // Brute (using sort and set)
    string longestWord2(vector<string> &words)
    {
        // TC: O(nlogn) n = no of words
        // SC: O(n) 
        
        unordered_set<string> st;
        // case 1
        sort(words.begin(), words.end());
        string res = "";
        for (auto it : words)
        {
            // case 2
            if (it.length() == 1 || st.count(it.substr(0, it.length() - 1)))
            {
                if (it.length() > res.length())
                    res = it;
                st.insert(it);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << "Result: " << s.longestWord(words) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-word-in-dictionary/

Youtube: https://www.youtube.com/watch?v=AWnBa91lThI&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=6

algorithm:

- Brute force:

- case 1: We sort the words, to make sure, we iterate the words from smallest
  to longest words length. So while inserting into the set, we have to just 
  ensure that its immediate prefix is present in the set or not. if yes
  we insert it, and move to next word.
- Sorting also helps to traverse the words in lexicographical order, hence the 
  answer will have the word that comes first in lexicographical order(if length is equal).
- We use set, since we have to check if its prefix exist or not (in O(1) time).

- Optimal Approach

- we insert all thw words in Trie DS. and then for each word, we check if its 
  the longest word in dictionary.
- While checking for each word, we have to chec if (flag==true), which means its 
  prefix exists. if (flag==false), means its prefix not exists, we return false.
- If (true), then we check if its the longest, if yes, we update longest,
  else we move to next word.
  
*/

/*

720. Longest Word in Dictionary

Given an array of strings words representing an English Dictionary, return
the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with
the smallest lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each
additional character being added to the end of a previous word.

Example 1:

Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time
by "w", "wo", "wor", and "worl".
Example 2:

Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words
in the dictionary. However, "apple" is lexicographically smaller than "apply".

*/