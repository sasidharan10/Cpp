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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode *InsertEnd(ListNode *head, int n)
    {
        ListNode *temp1 = new ListNode(n);
        if (head == NULL)
        {
            head = temp1;
            return head;
        }
        ListNode *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
        return head;
    }
    void print(ListNode *p)
    {
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
    }
    bool dfs(TreeNode *root, ListNode *head)
    {
        if (head == nullptr)
            return true;
        if (root == nullptr)
            return false;
        if (root->val != head->val)
            return false;

        bool lt = dfs(root->left, head->next);
        bool rt = dfs(root->right, head->next);
        return lt | rt;
    }
    bool solve(TreeNode *root, ListNode *head)
    {
        if (root == nullptr)
            return false;
        if (root->val == head->val)
        {
            bool ct = dfs(root, head);
            if (ct == true)
                return true;
        }
        bool lt = solve(root->left, head);
        bool rt = solve(root->right, head);
        return (lt | rt);
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        // TC: O(n*m) n= tree  nodes, m = list nodes.
        // SC: O(n+m) resurcion stack
        
        return solve(root, head);
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);

    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);
    root->right->left->left->left = new TreeNode(1);
    root->right->left->left->right = new TreeNode(3);
    cout << "\nTree: ";
    s.inorder(root);

    ListNode *head = nullptr;
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 8);
    cout << "\nList: ";
    s.print(head);
    cout << endl;
    cout << "\nResult: " << s.isSubPath(head, root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/linked-list-in-binary-tree

Youtube: https://www.youtube.com/watch?v=Ypzg7G3kg5A

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Linked%20List%20in%20Binary%20Tree.cpp

algorithm:

- Optimal Approach:

- Visit every  tree node and check if(root->val == head->val).
- If yes, then perform a dfs from that node, and check if these exist a path,
  which is equal to the linked list.
- If yes, return true, ro else false.

*/

/*

1367. Linked List in Binary Tree

Given a binary tree root and a linked list with head as the first node.
Return True if all the elements in the linked list starting from the head correspond to some
downward path connected in the binary tree otherwise return False.
In this context downward path means a path that starts at some node and goes downwards.

Example 1:

Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.

Example 2:

Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true

Example 3:

Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.

Constraints:

The number of nodes in the tree will be in the range [1, 2500].
The number of nodes in the list will be in the range [1, 100].
1 <= Node.val <= 100 for each node in the linked list and binary tree.

*/

/*
************* Java Code **************

    public static boolean dfs(TreeNode root, ListNode head) {
        if (head == null)
            return true;
        if (root == null)
            return false;
        if (root.val != head.val)
            return false;

        boolean lt = dfs(root.left, head.next);
        boolean rt = dfs(root.right, head.next);
        return lt | rt;
    }

    public static boolean solve(TreeNode root, ListNode head) {
        if (root == null)
            return false;
        if (root.val == head.val) {
            boolean ct = dfs(root, head);
            if (ct == true)
                return true;
        }
        boolean lt = solve(root.left, head);
        boolean rt = solve(root.right, head);
        return (lt | rt);
    }

    public static boolean isSubPath(ListNode head, TreeNode root) {
        return solve(root, head);
    }

*/