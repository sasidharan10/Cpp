#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
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
    void printList(ListNode *head)
    {
        cout << "List: ";
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
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
    TreeNode *sortedListToBSTUtil2(vector<int> v, int lt, int rt)
    {
        if (lt > rt)
            return nullptr;
        int mid = lt + (rt - lt) / 2;
        TreeNode *root = new TreeNode(v[mid]);
        root->left = sortedListToBSTUtil2(v, lt, mid - 1);
        root->right = sortedListToBSTUtil2(v, mid + 1, rt);
        return root;
    }
    TreeNode *sortedListToBST2(ListNode *head)
    {
        // TC: O(2n)
        // SC: O(n)

        vector<int> v;
        getList(head, v);
        TreeNode *root = sortedListToBSTUtil2(v, 0, v.size() - 1);
        return root;
    }
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        if (fast)
            fast = fast->next;
        else
            return slow;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        return slow;
    }
    TreeNode *sortedListToBSTUtil(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (head && !head->next)
        {
            TreeNode *temp = new TreeNode(head->val);
            return temp;
        }
        ListNode *prev = findMid(head);
        ListNode *mid = prev->next;
        ListNode *rt = mid->next;
        mid->next = nullptr;
        prev->next = nullptr;
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBSTUtil(head);
        root->right = sortedListToBSTUtil(rt);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        // TC: O(n^2)
        // SC: O(1)

        TreeNode *root = sortedListToBSTUtil(head);
        return root;
    }
    void getList(ListNode *head, vector<int> &v)
    {
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 6);
    head = s.InsertEnd(head, 7);
    cout << "\nList: ";
    s.printList(head);
    TreeNode *root = s.sortedListToBST(head);
    cout << "\nTree: ";
    s.inorder(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

Algorithm:



*/