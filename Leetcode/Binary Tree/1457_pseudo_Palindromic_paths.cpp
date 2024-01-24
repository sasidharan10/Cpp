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
    // brute force
    int findPaths2(TreeNode *root, vector<int> mp)
    {
        // TC: O(n)
        // SC: O(h) stack space + O(10)
        
        if (!root)
            return 0;
        if (!root->left && !root->right)
        {
            mp[root->val]++;
            int oddsCount = 0;
            for (auto &&it : mp)
            {
                if (it % 2 != 0 && oddsCount == 0)
                    oddsCount = 1;
                else if (it % 2 != 0)
                    return 0;
            }
            return 1;
        }
        mp[root->val]++;
        int lt = findPaths2(root->left, mp);
        int rt = findPaths2(root->right, mp);
        return lt + rt;
    }

    // Optimal using bit manipulation
    int findPaths(TreeNode *root, int val)
    {
        // TC: O(n)
        // SC: O(h) stack space

        if (!root)
            return 0;
        if (!root->left && !root->right)
        {
            val = (val^(1<<root->val));
            if ((val & (val - 1)) == 0)
                return 1;
            else
                return 0;
        }
        val = (val^(1<<root->val));
        int lt = findPaths(root->left, val);
        int rt = findPaths(root->right, val);
        return lt + rt;
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> mp(10, 0);
        // return findPaths2(root, mp);
        return findPaths(root, 0);
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);
    cout << "Total Pseudo-Palindromic Paths: " << s.pseudoPalindromicPaths(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

Youtube: https://www.youtube.com/watch?v=FK-Fztwj2gM

algorithm:

- Brute Force Approach:

- We need to find the no of paths, whose nodes are pseudo-palindromic, 
  like [2, 2, 3] is pseudo-palindromic, since it can be rearraged to
  make it a palindrome like this [2, 3, 2].
- The given numbers are pseudo-palindromic, if it contains only 1 number
  whose frequency is odd, and all other numbers occur at even times.
- If the freq of 2 or more numbers are odd, then it cannot be pseudo-palindromic.
- Its given in the question, that the nodes valies will be in the range
  1 - 9, hence we can carry a map[10] and keep track of freq of each number
  until we reach the leaf node.
- At leaf node, we check if the nodes in this path are pseudo-palindromic by
  checking the freq of the numbers.

- Optimal Approach:

- Since its given that the number will be from 1 - 9, we can use bit manipulation here.
- we use the first 10 bits of a number to represent the numbers.
- We use a variable "val".
- The given number can be represented in 10-bit by using this formula:
  val = (val^(1<<root->val)).
- If the given number is 4, it will be represented like this in the
  variable "val": [0 0 0 0 0 0 1 0 0 0]
- Hence, the numbers wil even occurences, will be get cancelled, by doing the 
  XOR operation.
- Hence only the numbers with odd no of occurnces will remain in the variable val.
- To find if there is only 1 number with odd no of occurence, we can use
  this formula: if ((val & (val - 1)) == 0).

- Example: [2, 2, 3]
- (val)    = [0 0 0 0 0 0 0 1 0 0]
- (val -1) = [0 0 0 0 0 0 0 0 1 1]
- AND ops  = [0 0 0 0 0 0 0 0 0 0] = 0 == 0, hence only 1 number with odd occurence.

- Example: [2, 1, 3]
- (val)    = [0 0 0 0 0 0 0 1 1 1]
- (val -1) = [0 0 0 0 0 0 0 1 1 0]
- AND ops  = [0 0 0 0 0 0 0 1 1 0] = 6 != 0, hence false.

*/

/*

1457. Pseudo-Palindromic Paths in a Binary Tree

Given a binary tree where node values are digits from 1 to 9. A path
in the binary tree is said to be pseudo-palindromic if at least one
permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

Example 1:

Input: root = [2,3,1,3,1,null,1]
Output: 2
Explanation: The figure above represents the given binary tree. There are
three paths going from the root node to leaf nodes: the red path [2,3,3],
the green path [2,1,1], and the path [2,3,1]. Among these paths only red
path and green path are pseudo-palindromic paths since the red path [2,3,3]
can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be
rearranged in [1,2,1] (palindrome).

Example 2:

Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1
Explanation: The figure above represents the given binary tree. There are
three paths going from the root node to leaf nodes: the green path [2,1,1],
the path [2,1,3,1], and the path [2,1]. Among these paths only the green
path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).

Example 3:

Input: root = [9]
Output: 1

*/