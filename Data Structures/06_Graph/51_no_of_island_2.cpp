#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
public:
    vector<int> parent, size;
    disjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution
{
public:
    bool isValid(int i, int j, int row, int col)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
            return true;
        else
            return false;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // TC: O(sz) * O(4 * alpha)
        // SC: O(n*m) + O(n*m)*2
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        disjointSet ds(n * m);
        int sz = operators.size();
        vector<int> ans;
        int cnt = 0;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        for (int i = 0; i < sz; i++)
        {
            int u = operators[i][0];
            int v = operators[i][1];
            if (vis[u][v] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[u][v] = 1;
            cnt++;
            for (int j = 0; j < 4; j++)
            {
                int newRow = dRow[j] + u;
                int newCol = dCol[j] + v;
                if (isValid(newRow, newCol, n, m) && vis[newRow][newCol] == 1)
                {
                    int nodeNumber = u * m + v;
                    int adjNumber = newRow * m + newCol;
                    if (ds.findUParent(nodeNumber) != ds.findUParent(adjNumber))
                    {
                        cnt--;
                        ds.unionBySize(nodeNumber, adjNumber);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 4, m = 5;
    vector<vector<int>> operators{{1, 1}, {0, 1}, {3, 3}, {3, 4}};
    vector<int> ans = s.numOfIslands(n, m, operators);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/number-of-islands/1
link: https://www.codingninjas.com/studio/problems/number-of-islands-ii_1266048

leetcode: 

Youtube: https://www.youtube.com/watch?v=Rn6B-Q4SNyA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=51

algorithm:

*/