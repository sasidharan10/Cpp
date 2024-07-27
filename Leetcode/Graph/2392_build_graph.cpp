#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Topo sort using DFS
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st, bool &cyclic)
    {
        vis[node] = 1;
        for (int it : adj[node])
        {
            if (vis[it] == 0)
                dfs(it, adj, vis, st, cyclic);
            else if (vis[it] == 1)
            {
                cyclic = true;
                return;
            }
        }
        vis[node] = 2;
        st.push(node);
    }
    vector<int> findOrderedList2(int k, vector<vector<int>> &rowConditions)
    {
        int n = rowConditions.size();
        vector<int> adj[k + 1];
        vector<int> vis(k + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int u = rowConditions[i][0];
            int v = rowConditions[i][1];
            adj[u].push_back(v);
        }
        stack<int> st;
        bool cyclic = false;
        for (int i = 1; i <= k; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, adj, vis, st, cyclic);
            }
        }
        if (cyclic)
            return {};
        vector<int> list;
        while (!st.empty())
        {
            list.push_back(st.top());
            st.pop();
        }
        return list;
    }

    // Topo sort using kahn's algo (BFS)
    vector<int> findOrderedList(int k, vector<vector<int>> &rowConditions)
    {
        // TC: O(n) + O(k) + O(k) ~= O(k)
        // SC: O(k) + O(k) ~= O(k)

        int n = rowConditions.size();
        vector<int> adj[k + 1];
        for (int i = 0; i < n; i++)
        {
            int u = rowConditions[i][0];
            int v = rowConditions[i][1];
            adj[u].push_back(v);
        }
        vector<int> inDegree(k + 1, 0);
        for (int i = 1; i <= k; i++)
        {
            for (int it : adj[i])
            {
                inDegree[it]++;
            }
        }
        queue<int> que;
        for (int i = 1; i <= k; i++)
        {
            if (inDegree[i] == 0)
                que.push(i);
        }
        int cnt = 0;
        vector<int> ans;
        while (!que.empty())
        {
            int node = que.front();
            que.pop();
            ans.push_back(node);
            cnt++;
            for (int it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    que.push(it);
            }
        }
        if (cnt == k)
            return ans;
        else
            return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        // TC: O(k^2)
        // SC: O(k^2)

        // vector<int> rowArray = findOrderedList2(k, rowConditions);
        // vector<int> colArray = findOrderedList2(k, colConditions);

        vector<int> rowArray = findOrderedList(k, rowConditions);
        vector<int> colArray = findOrderedList(k, colConditions);
        if (rowArray.size() == 0 || colArray.size() == 0)
            return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));

        // T.C: O(k^2)
        // S.C: O(1)
        // for (int i = 0; i < k; i++) {
        //     for (int j = 0; j < k; j++) {
        //         if (rowArray[i] == colArray[j]) {
        //             matrix[i][j] = rowArray[i];
        //         }
        //     }
        // }

        // OR

        // T.C: O(k)
        // S.C: O(k)
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < k; i++)
        {
            int row = rowArray[i];
            int col = colArray[i];
            mp[row].first = i;
            mp[col].second = i;
        }
        for (int i = 1; i <= k; i++)
        {
            int row = mp[i].first;
            int col = mp[i].second;
            matrix[row][col] = i;
        }
        return matrix;
    }
};
int main()
{
    Solution s;
    // int k = 3;
    // vector<vector<int>> rowConditions = {{1, 2}, {3, 2}}, colConditions = {{2, 1}, {3, 2}};
    int k = 8;
    vector<vector<int>> rowConditions = {{1, 2}}, colConditions = {{5, 7}, {2, 7}, {4, 3}, {6, 7}, {4, 3}, {2, 3}, {6, 2}};
    vector<vector<int>> ans = s.buildMatrix(k, rowConditions, colConditions);
    cout << "Result: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/build-a-matrix-with-conditions

Youtube: https://www.youtube.com/watch?v=QyrmIu4Vo8A

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Topological%20Sorting/Build%20a%20Matrix%20With%20Conditions.cpp

algorithm:

- Optimal Approach:

- First we need to find whether the given ordering is possible or not.
- Like [[1, 2], [2, 1] is not possible.
- We use topo sort to solve this issue. It will help us to find whether the ordering is
  possible. If possible, it will give the numbers in order.
- So convert the numbers into a graph, and perform topo sort for row and column.
-

*/

/*

2392. Build a Matrix With Conditions

You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The
remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is strictly above the row at which the number belowi
appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number
righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

Example 1:

Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.

Example 2:

Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3
to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.

Constraints:

2 <= k <= 400
1 <= rowConditions.length, colConditions.length <= 10^4
rowConditions[i].length == colConditions[i].length == 2
1 <= abovei, belowi, lefti, righti <= k
abovei != belowi
lefti != righti

*/

/*
************* Java Code **************



*/