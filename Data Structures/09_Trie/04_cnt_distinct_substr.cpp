#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];

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
};

class Solution
{
public:
    int countDistinctSubstrings(string &s)
    {
        Node *root = new Node();
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            Node *node = root;
            for (int j = i; j < n; j++)
            {
                if (!node->containKey(s[j]))
                {
                    cnt++;
                    node->put(s[j], new Node());
                }
                node = node->get(s[j]);
            }
        }
        return cnt + 1;
    }
};
int main()
{
    Solution s;
    // string str = "sds";
    string str = "abc";
    cout << "Result: " << s.countDistinctSubstrings(str) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292

leetcode:

Youtube: https://www.youtube.com/watch?v=RV0QeTyHZxo&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=4

algorithm:

- Whenever we insert a new char in the trie, it means it will be a distinct
  sub string, hence we increase the count, and return the count.
- return (count + 1) to count the empty sub String also.

*/

/*

Count Distinct Substrings

Sample Input 1 :
2
sds
abc

Sample Output 1 :
6
7

Explanation of Sample Input 1 :

In the first test case, the 6 distinct substrings are { ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }

In the second test case, the 7 distinct substrings are {‘a’, ‘b’, ‘c’, “ab”, “bc”, “abc”, “” }.

*/