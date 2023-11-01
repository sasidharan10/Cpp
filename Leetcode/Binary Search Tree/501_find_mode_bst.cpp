#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *insertNode(TreeNode *root, int n)
    {
        if (root == nullptr)
        {
            TreeNode *temp = new TreeNode(n);
            return temp;
        }
        if (n <= root->val)
            root->left = insertNode(root->left, n);
        else
            root->right = insertNode(root->right, n);
        return root;
    }
    void inorder1(TreeNode *root, unordered_map<int, int> &mp)
    {
        if (root == NULL)
            return;
        inorder1(root->left, mp);
        mp[root->val]++;
        inorder1(root->right, mp);
    }
    // brute force
    vector<int> findMode2(TreeNode *root)
    {
        unordered_map<int, int> mp;
        inorder1(root, mp);
        vector<int> ans;
        int maxFreq = 0;
        for (auto &&i : mp)
        {
            if (i.second > maxFreq)
            {
                ans.clear();
                ans.push_back(i.first);
                maxFreq = i.second;
            }
            else if (i.second == maxFreq)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
    void inorder2(TreeNode *root, int &prev, int &curFreq, int &mostFreq, vector<int> &ans)
    {
        if (root == NULL)
            return;
        inorder2(root->left, prev, curFreq, mostFreq, ans);
        int cur = root->val;
        if (prev == cur)
            curFreq++;
        else
            curFreq = 1;
        if (curFreq > mostFreq)
        {
            ans.clear();
            ans.push_back(cur);
            mostFreq = curFreq;
        }
        else if (curFreq == mostFreq)
        {
            ans.push_back(cur);
        }
        prev = cur;
        inorder2(root->right, prev, curFreq, mostFreq, ans);
    }
    // better
    vector<int> findMode(TreeNode *root)
    {
        vector<int> ans;
        int prev = -1e9;
        int curFreq = 0;
        int mostFreq = 0;
        inorder2(root, prev, curFreq, mostFreq, ans);
        return ans;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(7);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(10);
    vector<int> ans = s.findMode(root);
    cout << "Most frequent Elements in BST: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-mode-in-binary-search-tree

Youtube: https://www.youtube.com/watch?v=tYoq7CMJP4A

algorithm:

*/