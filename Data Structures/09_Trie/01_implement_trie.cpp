#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

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
    // setting flag to true at the end of the word
    void setEnd()
    {
        flag = true;
    }
    // checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        int n = word.length();
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

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        int n = prefix.length();
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{
    Trie t;
    t.insert("hello");
    t.insert("help");
    cout << "search(\"hello\"): " << t.search("hello") << endl;
    cout << "startsWith(\"hel\"): " << t.startsWith("hel") << endl;
    cout << "search(\"hel\"): " << t.search("hel") << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/implement-trie_631356

leetcode: https://leetcode.com/problems/implement-trie-prefix-tree

Youtube: https://www.youtube.com/watch?v=dBGUmUQhjaM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=1

algorithm:

*/

/*






*/