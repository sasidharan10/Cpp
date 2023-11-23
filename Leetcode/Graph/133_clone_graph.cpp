#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    // DFS
    void dfs(Node *node, Node *clone_node, vector<Node *> &v)
    {
        for (auto &&n : node->neighbors)
        {
            if (!v[n->val])
            {
                Node *clone = new Node(n->val);
                v[n->val] = clone;
                clone_node->neighbors.push_back(clone);
                dfs(n, clone, v);
            }
            else
            {
                clone_node->neighbors.push_back(v[n->val]);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        Node *clone_Node = new Node(node->val);
        vector<Node *> v(101, nullptr);
        v[node->val] = clone_Node;
        dfs(node, clone_Node, v);
        return clone_Node;
    }

    // BFS
    void bfs(vector<Node *> &v, queue<Node *> &q)
    {
        while (!q.empty())
        {
            Node *node = q.front();
            Node *clone_Node = v[node->val];
            q.pop();
            for (auto &&n : node->neighbors)
            {
                if (!v[n->val])
                {
                    Node *clone = new Node(n->val);
                    v[n->val] = clone;
                    clone_Node->neighbors.push_back(clone);
                    q.push(n);
                }
                else
                {
                    clone_Node->neighbors.push_back(v[n->val]);
                }
            }
        }
    }
    Node *cloneGraph2(Node *node)
    {
        if (!node)
            return nullptr;
        Node *clone_Node = new Node(node->val);
        vector<Node *> v(101, nullptr);
        v[node->val] = clone_Node;
        queue<Node *> q;
        q.push(node);
        bfs(v, q);
        return clone_Node;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/