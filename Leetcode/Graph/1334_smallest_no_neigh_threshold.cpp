#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getCity(int n, int distanceThreshold, vector<vector<int>> &distMatrix)
    {
        int minDistance = INT_MAX;
        int res = -1;
        for (int i = 0; i < n; i++)
        {
            int currDistance = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && distMatrix[i][j] <= distanceThreshold)
                    currDistance++;
            }
            if (currDistance <= minDistance)
            {
                minDistance = currDistance;
                res = i;
            }
        }
        return res;
    }

    // Dijkstra algo
    void dijkstra(int node, int n, vector<int> &dist, unordered_map<int, vector<pair<int, int>>> &adj)
    {
        //T.C : O(V * ElogV) * V (since We call Dijkstra's for each vertex).
        //In worst case , max edges = V*(V-1)/2
        //O(V * V * (V-1)/2 * log V)
        //Which is approximately equal to O(V^3 * log V)
        //S.C : O(V^2)

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node});
        dist[node] = 0;
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

    // Bellman Ford Algo
    void bellmanFord(int node, int n, vector<int> &dist, vector<vector<int>> &edges)
    {
        //T.C : O(V * (V * E)) * V (since We call Bellman(V*E) for each vertex.)
        //In worst case , max edges = V*(V-1)/2
        //O(V * V*(V-1)/2 * log V)
        //Which is approximately equal to O(V^4)
        //S.C : O(V^2)

        int m = edges.size();
        dist[node] = 0;
        for (int i = 0; i < n - 1; i++) // n - 1 times relaxing the edges
        {
            for (int j = 0; j < m; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
                // Bi directional
                if (dist[v] != 1e9 && dist[v] + wt < dist[u])
                {
                    dist[u] = dist[v] + wt;
                }
            }
        }
    }

    // Floyd Warshal algo
    void floydWarshal(int n, vector<vector<int>> &distMatrix, vector<vector<int>> &edges)
    {
        // TC: O(V^3)
        // SC: O(V^2)
        
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            distMatrix[u][v] = wt;
            distMatrix[v][u] = wt;
        }
        // a node to itself has 0 distance
        for (int i = 0; i < n; i++)
        {
            distMatrix[i][i] = 0;
        }

        // Floyd - Warshall algo
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (distMatrix[i][k] == INT_MAX || distMatrix[k][j] == INT_MAX)
                        continue;
                    distMatrix[i][j] = min(distMatrix[i][j], distMatrix[i][k] + distMatrix[k][j]);
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        int m = edges.size();
        vector<vector<int>> distanceMatrix(n, vector<int>(n, 1e9));
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        // for (int i = 0; i < n; i++)
        // {
        //     dijkstra(i, n, distanceMatrix[i], adj);
        //     bellmanFord(i, n, distanceMatrix[i], edges);
        // }
        floydWarshal(n, distanceMatrix, edges);
        return getCity(n, distanceThreshold, distanceMatrix);
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges{{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int n = 4;
    int distanceThreshold = 4;
    cout << "City With the Smallest Number of Neighbors at a Threshold Distance: ";
    cout << s.findTheCity(n, edges, distanceThreshold) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

leetcode: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

Youtube: https://www.youtube.com/watch?v=PwMVNSJ5SLI&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=46

algorithm:

- Better Approach:

- Dijkstra algo algo:
- take each node as src, and find the shortest path to all nodes.
- Hence we create a matrix, which will have dist[] for all nodes(results into 2D array).
- We send each node as source and its dist[], then find the shortest path to all other nodes.
- After we send that matrix to another function getCity(), where it will check for each node,
  how many paths are having (distMatrix[i][j] <= distanceThreshold), if yes, increase the cnt.
- Then we find the minimum, and return the node with least cnt.

- Bellman Ford algo:
- We will create the distance matrix as before and take each node as source, calculate the dist[].
- Note: we need to relax the edges from both directions, u -> v and from v -> u, since
  its an bi-directional graph.
- Again we use the same function getCity() to find the city with min paths.

- Optimal Approach:

- Floyd Warshall algo:
- Since we have to find the shortest from every node to every other node, its better to use
  FW algo, since it will give the distance matrix in one go.
- Then we can use getCity(), and return the city with min paths.

*/

/*

1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti]
represents a bidirectional and weighted edge between cities fromi and toi, and given the integer
distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose
distance is at most distanceThreshold, If there are multiple such cities, return the city with
the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges'
weights along that path.

Example 1:

Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph.
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2]
City 1 -> [City 0, City 2, City 3]
City 2 -> [City 0, City 1, City 3]
City 3 -> [City 1, City 2]
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3
since it has the greatest number.

Example 2:

Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph.
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1]
City 1 -> [City 0, City 4]
City 2 -> [City 3, City 4]
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3]
The city 0 has 1 neighboring city at a distanceThreshold = 2.

*/

/*
************* Java Code **************

    public static int getCity(int n, int distanceThreshold, int[][] distMatrix)
    {
        int minDistance = Integer.MAX_VALUE;
        int res = -1;
        for (int i = 0; i < n; i++)
        {
            int currDistance = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && distMatrix[i][j] <= distanceThreshold)
                    currDistance++;
            }
            if (currDistance <= minDistance)
            {
                minDistance = currDistance;
                res = i;
            }
        }
        return res;
    }

// Floyd Warshall

    public static void floydWarshal(int n, int[][] distMatrix, int[][] edges)
    {
        int m = edges.length;
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            distMatrix[u][v] = wt;
            distMatrix[v][u] = wt;
        }
        // a node to itself has 0 distance
        for (int i = 0; i < n; i++)
        {
            distMatrix[i][i] = 0;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (distMatrix[i][k] == Integer.MAX_VALUE || distMatrix[k][j] == Integer.MAX_VALUE)
                        continue;
                    distMatrix[i][j] = Math.min(distMatrix[i][j], distMatrix[i][k] + distMatrix[k][j]);
                }
            }
        }
    }

// Dijkstra Algo

    public static void dijkstra(int node, int n, int[] dist, Map<Integer, List<int[]>> adj) {
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.offer(new int[] { 0, node });
        dist[node] = 0;
        while (!pq.isEmpty()) {
            int dis = pq.peek()[0];
            int u = pq.peek()[1];
            pq.poll();
            if (!adj.containsKey(u))
                continue;
            for (int[] it : adj.get(u)) {
                int v = it[0];
                int dt = it[1];
                if (dist[u] + dt < dist[v]) {
                    dist[v] = dist[u] + dt;
                    pq.offer(new int[] { dist[u] + dt, v });
                }
            }
        }
    }

    public static int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int m = edges.length;
        int[][] distanceMatrix=new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(distanceMatrix[i], Integer.MAX_VALUE);
        }
        Map<Integer, List<int[]>> adj = new HashMap<>();
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[]{v, wt});
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[]{u, wt});
        }
        // for (int i = 0; i < n; i++)
        // {
        //     dijkstra(i, n, distanceMatrix[i], adj);
        // }
        floydWarshal(n, distanceMatrix, edges);
        return getCity(n, distanceThreshold, distanceMatrix);
    }

*/