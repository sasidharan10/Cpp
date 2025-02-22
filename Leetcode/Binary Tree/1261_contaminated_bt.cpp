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
class FindElements
{
public:
    unordered_set<int> uset;
    void bfs(TreeNode *root)
    {
        queue<TreeNode *> que;
        root->val = 0;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *temp = que.front();
            int x = temp->val;
            que.pop();
            uset.insert(x);
            if (temp->left != nullptr)
            {
                temp->left->val = x * 2 + 1;
                que.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                temp->right->val = x * 2 + 2;
                que.push(temp->right);
            }
        }
    }
    void dfs(TreeNode *root, int value)
    {
        if (root == nullptr)
            return;
        uset.insert(value);
        if (root->left != nullptr)
            dfs(root->left, value * 2 + 1);
        if (root->right != nullptr)
            dfs(root->right, value * 2 + 2);
    }
    FindElements(TreeNode *root)
    {
        uset.clear();
        // dfs(root, 0);
        bfs(root);
    }

    bool find(int target)
    {
        if (uset.find(target) != uset.end())
            return true;
        else
            return false;
    }
    void check()
    {
        cout << "List: ";
        for (int it : uset)
            cout << it << ", ";
        cout << endl;
    }
};
class Solution
{
public:
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(-1);
    FindElements *fe = new FindElements(root);
    // fe->check();
    cout << "find(1): " << fe->find(1) << endl;
    cout << "find(3): " << fe->find(3) << endl;
    cout << "find(5): " << fe->find(5) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

Youtube: https://www.youtube.com/watch?v=abqFdXyeAxA

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Find%20Elements%20in%20a%20Contaminated%20Binary%20Tree.cpp

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

1261. Find Elements in a Contaminated Binary Tree

Given a binary tree with the following rules:

root.val == 0
For any treeNode:
If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.

Example 1:

Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]);
findElements.find(1); // return False
findElements.find(2); // return True

Example 2:

Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False

Example 3:

Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True

Constraints:

TreeNode.val == -1
The height of the binary tree is less than or equal to 20
The total number of nodes is between [1, 10^4]
Total calls of find() is between [1, 10^4]
0 <= target <= 10^6

*/

/*
************* Java Code **************

    public static class FindElements {
        public static Set<Integer> hashSet = new HashSet<>();

        void bfs(TreeNode root) {
            Queue<TreeNode> que = new LinkedList<>();
            root.val = 0;
            que.offer(root);
            while (!que.isEmpty()) {
                TreeNode temp = que.poll();
                int x = temp.val;
                hashSet.add(x);
                if (temp.left != null) {
                    temp.left.val = x * 2 + 1;
                    que.offer(temp.left);
                }
                if (temp.right != null) {
                    temp.right.val = x * 2 + 2;
                    que.offer(temp.right);
                }
            }
        }

        public static void dfs(TreeNode root, int value) {
            if (root == null)
                return;
            hashSet.add(value);
            if (root.left != null)
                dfs(root.left, value * 2 + 1);
            if (root.right != null)
                dfs(root.right, value * 2 + 2);
        }

        public FindElements(TreeNode root) {
            hashSet.clear();
            // dfs(root, 0);
            bfs(root);
        }

        public static boolean find(int target) {
            if (hashSet.contains(target))
                return true;
            else
                return false;
        }

    }

*/