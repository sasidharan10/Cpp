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
    bool isEnd()
    {
        return flag;
    }
    void setEnd()
    {
        flag = true;
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
    vector<string> getList(string prefix)
    {
        vector<string> list;
        int n = prefix.length();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(prefix[i]))
                return {};
            node = node->get(prefix[i]);
        }
        dfs(node, prefix, list);
        return list;
    }
    void dfs(Node *node, string prefix, vector<string> &list)
    {
        if (list.size() == 3)
            return;
        if (node->isEnd())
            list.push_back(prefix);
        for (int i = 0; i < 26; i++)
        {
            char ch = 'a' + i;
            if (node->containKey(ch))
                dfs(node->get(ch), prefix + ch, list);
        }
    }
};
class Solution
{
public:
    vector<vector<string>> suggestedProducts2(vector<string> &products, string searchWord)
    {
        // TC: O(n)
        // SC: O(n)
        
        Trie t;
        vector<vector<string>> ans;
        int n = products.size();
        for (int i = 0; i < n; i++)
        {
            t.insert(products[i]);
        }
        int m = searchWord.length();
        string prefix = "";
        for (int i = 0; i < m; i++)
        {
            prefix += searchWord[i];
            vector<string> temp = t.getList(prefix);
            ans.push_back(temp);
        }
        return ans;
    }
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        // TC: O(m) * O(nLogn)
        // SC: O(n)
        
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int start = 0, ind;
        int n = products.size();
        int m = searchWord.length();
        string prefix = "";
        for (int i = 0; i < m; i++)
        {
            prefix += searchWord[i];
            ind = lower_bound(products.begin() + start, products.end(), prefix) - products.begin();
            vector<string> temp;
            for (int j = ind; j < min(ind + 3, n) && !products[j].compare(0, prefix.length(), prefix); j++)
            {
                temp.push_back(products[j]);
            }
            ans.push_back(temp);
            start = ind;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> products{"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    vector<vector<string>> ans = s.suggestedProducts(products, searchWord);
    cout << "Result: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/search-suggestions-system

Youtube: https://www.youtube.com/watch?v=lbfi2OZL0Ls

algorithm:

*/

/*

1268. Search Suggestions System

You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products
after each character of searchWord is typed. Suggested products should
have common prefix with searchWord. If there are more than three products
with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],
["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]

Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.

*/