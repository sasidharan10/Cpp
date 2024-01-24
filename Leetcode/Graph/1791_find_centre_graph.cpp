#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better
    int findCenter2(vector<vector<int>> &edges)
    {
        // TC: O(2) ~ O(1)
        // SC: O(3) ~ O(1)
        
        int n = edges.size();
        unordered_set<int> st;
        for (int i = 0; i < 2; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            if (st.find(u) != st.end())
                return u;
            if (st.find(v) != st.end())
                return v;
            st.insert(u);
            st.insert(v);
        }
        return -1;
    }

    // Optimal
    int findCenter(vector<vector<int>> &edges)
    {
        // TC: O(1)
        // SC: O(1)

        int n = edges.size();
        int u1 = edges[0][0];
        int v1 = edges[0][1];

        int u2 = edges[0][0];
        int v2 = edges[0][1];

        if (u1 == u2 || u1 == v2)
            return u1;
        else if (v1 == v2 || v1 == u2)
            return v1;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{1, 2}, {5, 1}, {1, 3}, {1, 4}};
    cout << "Center Node: " << s.findCenter(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-center-of-star-graph/

Youtube:

algorithm:

- Intuition is same for both approaches. its given, the graph is a start graph, 
  hence every node present in the graph will have a edge with the center node.
- Hence, we can just take 2 edges and check which node is apprearing in both
  the edges, as that will be the center node.

*/

/*

1791. Find Center of Star Graph

There is an undirected star graph consisting of n nodes labeled from 1 to n.
A star graph is a graph where there is one center node and exactly n - 1 edges
that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi]
indicates that there is an edge between the nodes ui and vi.
Return the center of the given star graph.

Example 1:

Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to
every other node, so 2 is the center.

Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1

*/