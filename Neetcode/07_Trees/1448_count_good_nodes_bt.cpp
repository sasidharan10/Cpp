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

    // Better
    void goodNodesUtil(TreeNode *root, int maxi, int &cnt)
    {
        if (!root)
            return;
        if (root->val >= maxi)
        {
            cnt++;
            maxi = root->val;
        }
        goodNodesUtil(root->left, maxi, cnt);
        goodNodesUtil(root->right, maxi, cnt);
    }
    int goodNodes2(TreeNode *root)
    {
        int cnt = 0, maxi = INT_MIN;
        goodNodesUtil(root, maxi, cnt);
        return cnt;
    }

    // Optimal - without reference variable
    int dfs(TreeNode *root, int maxi)
    {
        if (!root)
            return 0; // base case: null node contributes 0 good nodes

        // Check if current node is "good" (greater than or equal to max so far)
        int res = (root->val >= maxi) ? 1 : 0;

        // Update max value seen along the path
        maxi = max(maxi, root->val);

        // Recurse into left and right subtrees and accumulate good nodes
        res += dfs(root->left, maxi);
        res += dfs(root->right, maxi);

        return res;
    }
    int goodNodes(TreeNode *root)
    {
        int maxi = INT_MIN;     // initialize with lowest possible value
        return dfs(root, maxi); // start DFS with root node
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    cout << "Count Good Nodes in Binary Tree: " << s.goodNodes(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-good-nodes-in-binary-tree

Youtube:

algorithm:

- Do pre-Order traversal, and check if current val >= maxi. if yes, then increase cnt+1;
- return cnt
- To keep track of maximum value at a path, just update the value, when we find a maxi
  value. calling by reference (&maxi) wil not work, as it will keep track
  of maxi value throughout the tree

- Optimal approach:

- Use DFS traversal to explore the tree.
- At each node, keep track of the maximum value encountered along the path from the root.
- A node is considered "good" if its value is greater than or equal to the maximum so far.
- If the node is good, increment the count.
- Recurse on left and right subtrees, passing the updated maximum.
- The initial max is set to INT_MIN to ensure the root is always counted as good.

*/

/*

1448. Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path
from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

Example 1:

Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:

Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.

*/

/*
************* Java Code **************

    public int goodNodes(TreeNode root) {
        int maxi = Integer.MIN_VALUE; // initialize with lowest possible value
        return dfs(root, maxi); // start DFS with root node
    }

    private int dfs(TreeNode root, int maxi) {
        if (root == null)
            return 0; // base case: null node contributes 0 good nodes

        // Check if current node is "good" (greater than or equal to max so far)
        int res = (root.val >= maxi) ? 1 : 0;

        // Update max value seen along the path
        maxi = Math.max(maxi, root.val);

        // Recurse into left and right subtrees and accumulate good nodes
        res += dfs(root.left, maxi);
        res += dfs(root.right, maxi);

        return res;
    }

*/