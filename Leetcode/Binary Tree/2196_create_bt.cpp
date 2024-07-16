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
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        int n = descriptions.size();
        unordered_set<int> uset;
        unordered_map<int, TreeNode *> mp;
        for (int i = 0; i < n; i++)
        {
            int parentval = descriptions[i][0];
            int currval = descriptions[i][1];
            int isLeft = descriptions[i][2];

            // for current node
            TreeNode *curr = nullptr;
            if (mp.find(currval) == mp.end())
            {
                curr = new TreeNode(currval);
                mp.insert({currval, curr});
            }
            else
                curr = mp[currval];

            // for parent node
            TreeNode *parent = nullptr;
            if (mp.find(parentval) == mp.end())
            {
                parent = new TreeNode(parentval);
                mp.insert({parentval, parent});
            }
            else
                parent = mp[parentval];

            if (isLeft == 1)
                parent->left = curr;
            else
                parent->right = curr;
            // adding childs into a set for finding the root.
            uset.insert(currval);
        }
        for (int i = 0; i < n; i++)
        {
            int parentval = descriptions[i][0];
            if (uset.find(parentval) == uset.end())
                return mp[parentval];
        }
        return nullptr;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    TreeNode *root = s.createBinaryTree(nums);
    cout << "\nTree: ";
    s.inorder(root);
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/create-binary-tree-from-descriptions

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- have a map to keep the record of nodes we created.
- we iterate through the given 2d array, and create the child and parent node (if not created)
  and link it as per description and update it into the map.
- If node, already created, then we take it from the map.
- In this way, the whole tree will be created.
- Now we ahve to return the root.
- Note: root will be the only node, which will not have a parent.
- So, we push all the child nodes into a unordered_set.
- Now the set will have all the nodes, except the root node.
- So we traverse the 2d array again and check all parent nodes, if it is present in the set.
- The node which is not present in the set, will be the root node.

*/

/*

2196. Create Binary Tree From Descriptions

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti]
indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

Example 1:

Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.

Example 2:

Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.

Constraints:

1 <= descriptions.length <= 10^4
descriptions[i].length == 3
1 <= parenti, childi <= 10^5
0 <= isLefti <= 1
The binary tree described by descriptions is valid.

*/

/*
************* Java Code **************

public TreeNode createBinaryTree(int[][] descriptions) {
        int n = descriptions.length;
        HashSet<Integer> uset = new HashSet<>();
        HashMap<Integer, TreeNode> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int parentval = descriptions[i][0];
            int currval = descriptions[i][1];
            int isLeft = descriptions[i][2];

            // for current node
            TreeNode curr = null;
            if (!mp.containsKey(currval)) {
                curr = new TreeNode(currval);
                mp.put(currval, curr);
            } else
                curr = mp.get(currval);

            // for parent node
            TreeNode parent = null;
            if (!mp.containsKey(parentval)) {
                parent = new TreeNode(parentval);
                mp.put(parentval, parent);
            } else
                parent = mp.get(parentval);

            if (isLeft == 1)
                parent.left = curr;
            else
                parent.right = curr;
            // adding childs into a set for finding the root.
            uset.add(currval);
        }
        for (int i = 0; i < n; i++) {
            int parentval = descriptions[i][0];
            if (!uset.contains(parentval))
                return mp.get(parentval);
        }
        return null;
    }

*/