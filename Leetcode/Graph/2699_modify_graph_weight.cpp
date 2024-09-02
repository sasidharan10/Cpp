#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dijkstraAlgo(int n, vector<vector<int>> &edges, int src, int dest)
    {
        // TC: O(E*logV)
        // SC: O(E + V)

        int m = edges.size();
        unordered_map<long long, vector<pair<long long, long long>>> adj;
        for (int i = 0; i < m; i++)
        {
            if (edges[i][2] == -1) // ignoring negative weighted edges.
                continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<int> dist(n, 2e9);
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            long long dst = pq.top().first;
            long long u = pq.top().second;
            pq.pop();
            for (auto it : adj[u])
            {
                long long v = it.first;
                long long d = it.second;
                if (dst + d < dist[v])
                {
                    dist[v] = dst + d;
                    pq.push({dst + d, v});
                }
            }
        }
        return dist[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        int m = edges.size();
        long long shortestDist = dijkstraAlgo(n, edges, source, destination);

        // case 1:
        if (shortestDist < target)
            return {};

        // case 2:
        bool matchedTarget = (shortestDist == target);
        if (matchedTarget)
        {
            for (int i = 0; i < m; i++)
            {
                if (edges[i][2] == -1)
                {
                    edges[i][2] = 2e9;
                }
            }
            return edges;
        }

        // case 3:
        for (int i = 0; i < m; i++)
        {
            if (edges[i][2] != -1)
                continue;

            if (matchedTarget == true)
                edges[i][2] = 2e9;
            else
                edges[i][2] = 1;

            if (!matchedTarget)
            {
                int newDist = dijkstraAlgo(n, edges, source, destination);
                if (newDist <= target)
                {
                    matchedTarget = true;
                    edges[i][2] += (target - newDist);
                }
            }
        }
        if (!matchedTarget)
            return {};

        return edges;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges{{4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}};
    int n = 5, source = 0, destination = 1, target = 5;
    vector<vector<int>> ans = s.modifiedGraphEdges(n, edges, source, destination, target);
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

leetcode: https://leetcode.com/problems/modify-graph-edge-weights

Youtube: https://www.youtube.com/watch?v=F6sRIQKslwA

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra'a%20Based%20Problems/Modify%20Graph%20Edge%20Weights.cpp

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

2699. Modify Graph Edge Weights

You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1,
and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between
nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive integer values in
the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes
equal to an integer target. If there are multiple modifications that make the shortest distance
between source and destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it is possible to make
the shortest distance from source to destination equal to target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive weights.

Example 1:

Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
Explanation: The graph above shows a possible modification to the edges, making the distance
from 0 to 1 equal to 5.

Example 2:

Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
Output: []
Explanation: The graph above contains the initial edges. It is not possible to make the distance
from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.

Example 3:

Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
Explanation: The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.

Constraints:

1 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= ai, bi < n
wi = -1 or 1 <= wi <= 10^7
ai != bi
0 <= source, destination < n
source != destination
1 <= target <= 10^9
The graph is connected, and there are no self-loops or repeated edges

*/

/*
************* Java Code **************

    public static int dijkstraAlgo(int n, int[][] edges, int src, int dest) {
        int m = edges.length;
        HashMap<Integer, List<int[]>> adj = new HashMap<>();
        for (int i = 0; i < m; i++) {
            if (edges[i][2] == -1)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[] { v, wt });
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[] { u, wt });
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        int[] dist = new int[n];
        Arrays.fill(dist, 2000000000);
        dist[src] = 0;
        pq.offer(new int[] { 0, src });
        while (!pq.isEmpty()) {
            int dst = pq.peek()[0];
            int u = pq.peek()[1];
            pq.poll();
            if (adj.get(u) == null)
                continue;
            for (int[] it : adj.get(u)) {
                int v = it[0];
                int d = it[1];
                if (dst + d < dist[v]) {
                    dist[v] = dst + d;
                    pq.offer(new int[] { dst + d, v });
                }
            }
        }
        return dist[dest];
    }

    public static int[][] modifiedGraphEdges(int n, int[][] edges, int source, int destination, int target) {
        int m = edges.length;
        long shortestDist = dijkstraAlgo(n, edges, source, destination);

        // case 1:
        if (shortestDist < target) {
            return new int[0][];
        }

        // case 2:
        boolean matchedTarget = (shortestDist == target);
        if (matchedTarget) {
            for (int i = 0; i < m; i++) {
                if (edges[i][2] == -1) {
                    edges[i][2] = 2000000000;
                }
            }
            return edges;
        }

        // case 3:
        for (int i = 0; i < m; i++) {
            if (edges[i][2] != -1)
                continue;

            if (matchedTarget == true)
                edges[i][2] = 2000000000;
            else
                edges[i][2] = 1;

            if (matchedTarget == false) {
                int newDist = dijkstraAlgo(n, edges, source, destination);
                if (newDist <= target) {
                    matchedTarget = true;
                    edges[i][2] += (target - newDist);
                }
            }
        }
        if (matchedTarget == false)
            return new int[0][];

        return edges;
    }

*/