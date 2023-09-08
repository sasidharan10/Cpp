#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
class cmp
{
public:
    bool operator()(node *n1, node *n2)
    {
        return n1->data > n2->data;
    }
};
class Solution
{
public:
    void traverse(node *root, string temp, vector<string> &ans)
    {
        if (!root->left && !root->right)
        {
            ans.push_back(temp);
            return;
        }
        traverse(root->left, temp + '0', ans);
        traverse(root->right, temp + '1', ans);
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        priority_queue<node *, vector<node *>, cmp> pq;
        for (int i = 0; i < f.size(); i++)
        {
            node *temp = new node(f[i]);
            pq.push(temp);
        }

        while (pq.size() > 1)
        {
            node *lt = pq.top();
            pq.pop();
            node *rt = pq.top();
            pq.pop();
            node *newNode = new node(lt->data + rt->data);
            newNode->left = lt;
            newNode->right = rt;
            pq.push(newNode);
        }
        node *root = pq.top();
        pq.pop();
        string temp = "";
        vector<string> ans;
        traverse(root, temp, ans);
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "abcdef";
    vector<int> nums{5, 9, 12, 13, 16, 45};
    int N = 6;
    vector<string> ans = s.huffmanCodes(str, nums, N);
    cout << "Huffman encoding: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

leetcode: 

Youtube: https://www.youtube.com/watch?v=HZOUwKCKF5o

algorithm: https://www.youtube.com/watch?v=uDS8AkTAcIU

*/