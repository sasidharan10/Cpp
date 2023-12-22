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
    string completeString(int n, vector<string> &a)
    {
        Trie t;
        for (auto &&it : a)
        {
            t.insert(it);
        }
        string longest = "";
        for (auto &&it : a)
        {
            if (t.checkCompleteString(it))
            {
                if (it.length() > longest.length())
                    longest = it;
                else if (it.length() == longest.length() && it < longest)
                    longest = it;
            }
        }
        if (longest == "")
            return "None";
        return longest;
    }
};
int main()
{
    Solution s;
    int n = 6;
    vector<string> nums{"n", "ni", "nin", "ninj", "ninja", "ninga"};
    cout << "Result: " << s.completeString(n, nums) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/complete-string_2687860

leetcode: https://leetcode.com/problems/longest-word-in-dictionary/

Youtube: https://www.youtube.com/watch?v=AWnBa91lThI&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=5

algorithm:

*/

/*

Complete String

Sample Input 1 :
2
6
n ni nin ninj ninja ninga
2
ab bc
Sample Output 1 :
ninja
None
Explanation Of Sample Input 1 :
For test case 1 we have,

All the prefixes of “ninja” -> “n”, “ni”, “nin”, “ninj” and “ninja” are
present in array ‘A’. So, “ninja” is a valid answer whereas for “ninga” ,
the prefix “ning” is not present in array ‘A’.

So we output “ninja”.

For test case 2 we have,

The prefixes of “ab” are “a” and “ab”. “a” is not present in
array ‘A’. So, “ab” is not a valid answer.

The prefixes of “bc” are “b” and “bc”. “b” is not present in
array ‘A’. So, “ab” is not a valid answer.

Since none of the strings is a valid answer we output “None”.

*/