#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool isWordEnd;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != nullptr);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *newNode)
    {
        links[ch - 'a'] = newNode;
    }
    void setEnd()
    {
        isWordEnd = true;
    }
    bool isEnd()
    {
        return isWordEnd;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    string search(string word)
    {
        Node *node = root;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i]))
                return word;
            node = node->get(word[i]);
            if (node->isEnd())
                return word.substr(0, i + 1);
        }
        return word;
    }
};
class Solution
{
public:
    string findRoot(string word, unordered_set<string> &st)
    {
        int m = word.length();
        for (int i = 1; i <= m; i++) // O(l)
        {
            string temp = word.substr(0, i); // O(l)
            if (st.find(temp) != st.end())
                return temp;
        }
        return word;
    }
    string replaceWords2(vector<string> &dictionary, string sentence)
    {
        // TC: O(n * l) + O(m * l * l)
        // SC: O(n * l)
        // n = number of words in the dictionary, m be the number of words in the sentence,
        // and l be the average length of each word.

        unordered_set<string> st(dictionary.begin(), dictionary.end());
        string result, word;
        stringstream ss(sentence);

        while (getline(ss, word, ' '))
        {
            result += findRoot(word, st) + ' ';
        }
        result.pop_back();
        return result;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        // TC: O(n * l) + O(m * l * l)
        // SC: O(n * l)
        // n = number of words in the dictionary, m be the number of words in the sentence,
        // and l be the average length of each word.

        Trie t;
        int n = dictionary.size();
        for (int i = 0; i < n; i++)  // O(n)
        {
            t.insert(dictionary[i]);
        }
        string result, word;
        stringstream ss(sentence);
        while (getline(ss, word, ' ')) // O(m)
        {
            result += t.search(word) + ' ';
        }
        result.pop_back();
        return result;
    }
};
int main()
{
    Solution s;
    vector<string> nums{"cat", "bat", "rat"};
    string str = "the cattle was rattled by the battery";
    cout << "Result: " << s.replaceWords(nums, str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/replace-words

Youtube: https://www.youtube.com/watch?v=EFskdMa-eBg
Youtube (Trie solution): https://www.youtube.com/watch?v=FxmFhwmKumU

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashSet/Replace%20Words.cpp
Code Link (Trie solution): https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Trie/Replace%20Words.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

648. Replace Words

In English, we have a concept called root, which can be followed by some other word to
form another longer word - let's call this word derivative. For example, when the root
"help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated
by spaces, replace all the derivatives in the sentence with the root forming it. If a
derivative can be replaced by more than one root, replace it with the root that
has the shortest length.

Return the sentence after the replacement.

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.

*/

/*
************* Java Code **************



*/