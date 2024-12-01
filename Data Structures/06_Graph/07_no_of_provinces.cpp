#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (int nbr : adj[node])
        {
            if (!vis[nbr])
                dfs(nbr, adj, vis);
        }
    }
    int numProvinces(vector<vector<int>> mat, int V)
    {
        // TC: ~O(n) or O(n) + O(n + 2E)
        // SC: O(n) + (n)
        
        vector<int> vis(V, 0);
        vector<int> adj[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (mat[i][j] && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    int n = 3;
    vector<vector<int>> adj{{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    cout << "No of provinces: " << s.numProvinces(adj, n);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1

leetcode: https://leetcode.com/problems/number-of-provinces/

Youtube: https://www.youtube.com/watch?v=ACzkVtewUYA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=7&pp=iAQB

algorithm:

*/

/*

547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected 
directly with city b, and city b is connected directly with city c, then city a is connected 
indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the 
jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 
Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

*/

/*   
************* Java Code **************



*/