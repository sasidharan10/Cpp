#include <bits/stdc++.h>
// #define P pair<int, int>
using namespace std;
class Solution
{
public:
    // Brute force - using dijkstra - Gives TLE.
    void dijkstra(int src, vector<int> &dist, unordered_map<int, vector<pair<int, int>>> &adj)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for (auto &&it : adj[u])
            {
                int v = it.first;
                int dt = it.second;
                if (dist[u] + dt < dist[v])
                {
                    dist[v] = dist[u] + dt;
                    pq.push({dist[u] + dt, v});
                }
            }
        }
    }
    long long minimumCost2(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        // TC: O(26 * E*logV) ~= O(E*logV)
        // SC: O(26 * 26)     ~= O(1)

        int n = original.size();
        int m = source.length();
        vector<vector<int>> distMatrix(26, vector<int>(26, INT_MAX));
        unordered_map<int, vector<pair<int, int>>> adj;
        vector<bool> vis(26, false);
        for (int i = 0; i < n; i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int wt = cost[i];
            adj[u].push_back({v, wt});
        }
        long long res = 0;
        for (int i = 0; i < m; i++)
        {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (!vis[u])
            {
                dijkstra(u, distMatrix[u], adj);
                vis[u] = true;
            }
            if (distMatrix[u][v] == INT_MAX)
                return -1;
            else
                res += distMatrix[u][v];
        }
        return res;
    }

    // Optimal Approach - Floyd Warshal algo
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        // TC: O(26*26*26) ~= O(n)
        // SC: O(26*26)    ~= O(1)

        int n = original.size();
        int m = source.length();
        vector<vector<int>> distMatrix(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < 26; i++)
        {
            distMatrix[i][i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int wt = cost[i];
            distMatrix[u][v] = min(distMatrix[u][v], wt);
        }

        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (distMatrix[i][k] == INT_MAX || distMatrix[k][j] == INT_MAX)
                        continue;
                    distMatrix[i][j] = min(distMatrix[i][j], distMatrix[i][k] + distMatrix[k][j]);
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < m; i++)
        {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (distMatrix[u][v] == INT_MAX)
                return -1;
            res += distMatrix[u][v];
        }
        return res;
    }
};
int main()
{
    Solution s;
    string source = "abcd", target = "acbe";
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'}, changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost = {2, 5, 5, 1, 2, 20};
    cout << "Result: " << s.minimumCost2(source, target, original, changed, cost) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-cost-to-convert-string-i

Youtube: https://www.youtube.com/watch?v=M8WnAIhTjmQ

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra'a%20Based%20Problems/Minimum%20Cost%20to%20Convert%20String%20I.cpp
Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Floyd%20Warshall/Minimum%20Cost%20to%20Convert%20String%20I.cpp

algorithm:

- Better Approach:

- Using Dijkstra algo:
- As given in the problem, we can convert only original[i] -> changed[i], and not vice-versa.
- By refering the 2 arrays, we can coonvert c -> b in 2 ways.
- c -> b, cost = 5.
- c -> e, cost = 1, e -> b, cost = 2, total = 3.
- We can see that, each letter can be converted into another letter in many ways, some
  and its cost vary in each case.
- This pattern is similar to a graph problem.
- We convert it into a graph, and change the letters into number from 0 - 25 since we have 
  to return the minimum cost only, so  letters don't matter.
- We also dont know, which letters will be present in the edges, but what we know is, there can be
  0-25 nodes possible in the graph. hence we take V = 26.
- We create the adjacency list, using original[i] and changed[i], put cost[i] as edge weight.
- Now we take source[i] as source, and find the shorted distance to all nodes using dijkstra algo.
- After finding the path, we take the target[i] as destination, and check if the path is valid. if yes,
  we add it to the res, or else, the path does not exist, so we directly return -1.

- Optimisation: 
- We use 2D matrix distMatrix[][] and fill the shortest dist array of all nodes from 0 - 25.
- We also use vis[] to mark if the current node's dist array is filled or not.
- So when we encounter the same node again, we dont have to fill the dist array again, hence
  reducign the TC.

- Optimal Approach:

- Instead of calculating the shortest dist[] for each source[i], we just use Floyd-Warshall algo
  and calculate the distMatrix[][] for all nodes from 0 - 25 in one go.
- Then using that distMatrix[][], we find the shortest apath from source[i] -> target[i]
  and return the result.

*/

/*

2976. Minimum Cost to Convert String I

You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English
letters. You are also given two 0-indexed character arrays original and changed, and an integer
array cost, where cost[i] represents the cost of changing the character original[i] to the
character changed[i].

You start with the string source. In one operation, you can pick a character x from the string
and change it to the character y at a cost of z if there exists any index j such that
cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of
operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"],
changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.

Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1,
followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3.
To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.

Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot
be changed from 'd' to 'e'.

*/

/*
************* Java Code **************

public static long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        int n = original.length;
        int m = source.length();
        int[][] distMatrix = new int[26][26];
        for (int i = 0; i < 26; i++) {
            Arrays.fill(distMatrix[i], Integer.MAX_VALUE);
            distMatrix[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int wt = cost[i];
            distMatrix[u][v] = Math.min(distMatrix[u][v], wt);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (distMatrix[i][k] == Integer.MAX_VALUE || distMatrix[k][j] == Integer.MAX_VALUE)
                        continue;
                    distMatrix[i][j] = Math.min(distMatrix[i][j], distMatrix[i][k] + distMatrix[k][j]);
                }
            }
        }
        long res = 0;
        for (int i = 0; i < m; i++) {
            int u = source.charAt(i) - 'a';
            int v = target.charAt(i) - 'a';
            if (distMatrix[u][v] == Integer.MAX_VALUE)
                return -1;
            res += distMatrix[u][v];
        }
        return res;
    }

*/