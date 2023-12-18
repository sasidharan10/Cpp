#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    // checks if the reference trie is present or not
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    // creating reference trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    // to get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    // increasing the word count
    void increaseEnd()
    {
        cntEndWith++;
    }
    // increasing the prefix count
    void increasePrefix()
    {
        cntPrefix++;
    }
    void decreaseEnd()
    {
        cntEndWith--;
    }
    void decreasePrefix()
    {
        cntPrefix--;
    }
    // get count of words
    int getEnd()
    {
        return cntEndWith;
    }
    // get count of prefix
    int getPrefix()
    {
        return cntPrefix;
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

    void insert(string &word)
    {
        int n = word.size();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        int n = word.size();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        int n = word.size();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word)
    {
        int n = word.size();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(word[i]))
            {
                return;
            }
            node = node->get(word[i]);
            node->decreasePrefix();
        }
        node->decreaseEnd();
    }
};

int main()
{
    Trie t;
    string word1 = "vivo";
    string word2 = "samsung";
    t.insert(word1);
    t.insert(word1);
    t.insert(word2);
    t.erase(word2);
    cout << "countWordsEqualTo(\"samsung\"): " << t.countWordsEqualTo(word1) << endl;
    cout << "countWordsEqualTo(\"vivo\"): " << t.countWordsEqualTo(word2) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/implement-trie_1387095

leetcode:

Youtube: https://www.youtube.com/watch?v=K5pcpkEMCN0&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=3

algorithm:

*/

/*






*/