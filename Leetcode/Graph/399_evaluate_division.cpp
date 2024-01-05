#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(string src, string dst, double product, double &ans, unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &vis)
    {
        if (vis.find(src) != vis.end())
            return;
        vis.insert(src);
        if (src == dst)
        {
            ans = product;
            return;
        }
        for (auto &&it : adj[src])
        {
            string v = it.first;
            double val = it.second;
            dfs(v, dst, product * val, ans, adj, vis);
        }
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < n; i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }
        vector<double> res;
        for (auto &&it : queries)
        {
            string src = it[0];
            string dst = it[1];

            double ans = -1.0;
            double product = 1.0;

            if (adj.find(src) != adj.end())
            {
                unordered_set<string> vis;
                dfs(src, dst, product, ans, adj, vis);
            }
            res.push_back(ans);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<string>> equations{{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> ans = s.calcEquation(equations, values, queries);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/evaluate-division

Youtube: https://www.youtube.com/watch?v=C6cm6IvqmyA

algorithm:

- it is a graph problem, where we need to find if src to destination possible, 
  if yes, then we take the prod of the path, and return the ans. if not,
  assign -1.0.
- a/b can be denoted as a -> b whose path val = values[i].
- b/a can be denoted as b -> b whose path val = 1.0/ values[i].
- from a src, we try all possible paths, and check if we reach the dst.
- If not, we assign ans as -1.0.
- While traversing, we take the prod of the values.

*/

/*

399. Evaluate Division

You are given an array of variable pairs equations and an array of real
numbers values, where equations[i] = [Ai, Bi] and values[i] represent
the equation Ai / Bi = values[i]. Each Ai or Bi is a string that
represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents
the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer
cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries
will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are
undefined, so the answer cannot be determined for them.

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0],
queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]

Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]

Explanation:

Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0

Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]],
values = [1.5,2.5,5.0],
queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]

Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:

Input: equations = [["a","b"]], values = [0.5],
queries = [["a","b"],["b","a"],["a","c"],["x","y"]]

Output: [0.50000,2.00000,-1.00000,-1.00000]

*/