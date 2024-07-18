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
    vector<int> dfs(TreeNode *root, int distance, int &cnt)
    {
        if (root == nullptr)
            return {0};
        if (root->left == nullptr && root->right == nullptr)
            return {1};
        vector<int> lt = dfs(root->left, distance, cnt);
        vector<int> rt = dfs(root->right, distance, cnt);
        int n = lt.size();
        int m = rt.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (lt[i] > 0 && rt[j] > 0 && lt[i] + rt[j] <= distance)
                    cnt++;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (lt[i] > 0)
                res.push_back(lt[i] + 1);
        }
        for (int j = 0; j < m; j++)
        {
            if (rt[j] > 0)
                res.push_back(rt[j] + 1);
        }
        return res;
    }

    // Using DFS
    int countPairs2(TreeNode *root, int distance)
    {
        // TC: O(n^2)
        // SC: O(n)

        int cnt = 0;
        vector<int> temp = dfs(root, distance, cnt);
        return cnt;
    }
    void findParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (root == nullptr)
            return;
        if (root->left != nullptr)
            parent[root->left] = root;
        if (root->right != nullptr)
            parent[root->right] = root;
        findParent(root->left, parent);
        findParent(root->right, parent);
    }
    void findLeafNodes(TreeNode *root, vector<TreeNode *> &leafNodes)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            leafNodes.push_back(root);
        findLeafNodes(root->left, leafNodes);
        findLeafNodes(root->right, leafNodes);
    }
    int findPairs(TreeNode *root, TreeNode *prev, int curr, int distance, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (root == nullptr || curr > distance)
            return 0;
        if (root->left == nullptr && root->right == nullptr && curr > 0 && curr <= distance)
            return 1;
        int lt = 0, rt = 0, up = 0;
        if (root->left != prev)
            lt = findPairs(root->left, root, curr + 1, distance, parent);
        if (root->right != prev)
            rt = findPairs(root->right, root, curr + 1, distance, parent);
        if (parent[root] != prev)
            up = findPairs(parent[root], root, curr + 1, distance, parent);
        return lt + rt + up;
    }

    // Converting into graph and using BFS
    int countPairs(TreeNode *root, int distance)
    {
        // TC: O(n^2)
        // SC: O(n)

        unordered_map<TreeNode *, TreeNode *> parent;
        parent.insert({root, nullptr});
        findParent(root, parent);
        vector<TreeNode *> leafNodes;
        findLeafNodes(root, leafNodes);
        int n = leafNodes.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += findPairs(leafNodes[i], nullptr, 0, distance, parent);
        }
        return cnt / 2;
    }
};
int main()
{
    Solution s;
    TreeNode *root = NULL;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    int distance = 2;
    cout << "Path: " << s.countPairs(root, distance) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/solutions/5493643/very-easy-sol-straight-forward-dfs-approach-vid-solution

Youtube: https://www.youtube.com/watch?v=vrbJ7aDuK-A

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Number%20of%20Good%20Leaf%20Nodes%20Pairs.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

1530. Number of Good Leaf Nodes Pairs

You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes
of a binary tree is said to be good if the length of the shortest path between them is less than or
equal to distance.

Return the number of good leaf node pairs in the tree.

Example 1:

Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between
them is 3. This is the only good pair.

Example 2:

Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good
because the length of ther shortest path between them is 4.

Example 3:

Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].

Constraints:

The number of nodes in the tree is in the range [1, 2^10].
1 <= Node.val <= 100
1 <= distance <= 10

*/

/*
************* Java Code **************

public static Map<TreeNode, TreeNode> parent;
    public static List<TreeNode> leafNodes;

    public static void findParent(TreeNode root) {
        if (root == null)
            return;
        if (root.left != null)
            parent.put(root.left, root);
        if (root.right != null)
            parent.put(root.right, root);
        findParent(root.left);
        findParent(root.right);
    }

    public static void findLeafNodes(TreeNode root) {
        if (root == null)
            return;
        if (root.left == null && root.right == null)
            leafNodes.add(root);
        findLeafNodes(root.left);
        findLeafNodes(root.right);
    }

    public static int findPairs(TreeNode root, TreeNode prev, int curr, int distance) {
        if (root == null || curr > distance)
            return 0;
        if (root.left == null && root.right == null && curr > 0 && curr <= distance)
            return 1;
        int lt = 0, rt = 0, up = 0;
        if (root.left != prev)
            lt = findPairs(root.left, root, curr + 1, distance);
        if (root.right != prev)
            rt = findPairs(root.right, root, curr + 1, distance);
        if (parent.get(root) != prev)
            up = findPairs(parent.get(root), root, curr + 1, distance);
        return lt + rt + up;
    }

    public static int countPairs(TreeNode root, int distance) {
        // TC: O(n^2)
        // SC: O(n)

        parent = new HashMap<>();
        parent.put(root, null);
        findParent(root);
        leafNodes = new ArrayList<>();
        findLeafNodes(root);
        int n = leafNodes.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += findPairs(leafNodes.get(i), null, 0, distance);
        }
        return cnt / 2;
    }

*/