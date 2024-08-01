#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - Using dijksra algo
    int secondMinimum2(int n, vector<vector<int>> &edges, int time, int change)
    {
        // TC: O(E*logV)
        // SC: O(V + E)

        int m = edges.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist1(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        dist1[1] = 0;
        while (!pq.empty())
        {
            int timePassed = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (dist2[n] != INT_MAX && u == n) // We reached n 2nd time means it's the second minimum
                return dist2[n];

            int temp = timePassed / change;
            if (temp % 2 != 0)
                timePassed = (temp + 1) * change;
            for (int v : adj[u])
            {
                int newTime = timePassed + time;
                if (dist1[v] > newTime)
                {
                    dist2[v] = dist1[v];
                    dist1[v] = newTime;
                    pq.push({timePassed + time, v});
                }
                else if (dist2[v] > newTime && dist1[v] != newTime)
                {
                    dist2[v] = newTime;
                    pq.push({timePassed + time, v});
                }
            }
        }
        return dist2[n];
    }

    // Optimal - Using BFS, and keeping freq count.
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        // TC: O(V + E)
        // SC: O(V + E)

        int m = edges.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist1(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);
        queue<pair<int, int>> que;
        que.push({1, 1});
        dist1[1] = 0;
        while (!que.empty())
        {
            int u = que.front().first;
            int freq = que.front().second;
            que.pop();

            int timePassed = (freq == 1) ? dist1[u] : dist2[u];

            if (dist2[n] != INT_MAX && u == n) // We reached n 2nd time means it's the second minimum
                return dist2[n];

            int temp = timePassed / change;
            if (temp % 2 != 0)
                timePassed = (temp + 1) * change;
            for (int v : adj[u])
            {
                int newTime = timePassed + time;
                if (dist1[v] == INT_MAX)
                {
                    dist1[v] = newTime;
                    que.push({v, 1});
                }
                else if (dist2[v] == INT_MAX && dist1[v] != newTime)
                {
                    dist2[v] = newTime;
                    que.push({v, 2});
                }
            }
        }
        return dist2[n];
    }
};
int main()
{
    Solution s;
    int n = 5, time = 3, change = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
    cout << "Result: " << s.secondMinimum(n, edges, time, change) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/second-minimum-time-to-reach-destination

Youtube: https://www.youtube.com/watch?v=_rnQKrA9xzA

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra'a%20Based%20Problems/Second%20Minimum%20Time%20to%20Reach%20Destination.cpp

algorithm:

- Brute Force Approach:

- We need to find the 2nd shortest path from source = 1 to dest = n.
- We can use dijkstra algo here. But we use 2 dist[] here, to stoer the shortest and 2nd shortest
  path.
- We can only move only when the time range in green. If time range is red, then we cannot move, 
  and have to wait, until it turns green.
- Moving from every node to every other node takes "time" minutes. lets take "time" = 3.
- The light changes for every "change" minutes, lets take "change" = 5.
- so for first 0-5 minutes, its green, then 5-10, its red, and so on.
- 0-5 = G
- 5-10 = R
- 10-15 = G
- 15-20 = R
- To find which range we fall in, we can use this formula: temp = timePassed/change.
- If (temp % 2 == 0) means green, or its red.
- If we are in green zone, we can just use the same time, as we don't have to wait.
- But if we are in red zone, then we have to wait until it turns green again.
- To find the next green zone, we can use this formula: timePassed = (temp + 1) * change;
- Thats its, now we use the Dijsktra also same as before, and update the dist1[] first, to
  store the shortest time, then update dist2[] to store 2nd shortest path.
- The 2nd shortest path, should be strictly shorter than the first path, hence we should not
  store same path in dist1[] and dist2[].
- After filing both arrays, we can return dist2[n].

- Optimal Approach:

- We can directly use a simple BFS traversal.
- Here instead of distance, we store freq along with node in the queue.
- We get the distance, with the help of freq.
- int timePassed = (freq == 1) ? dist1[u] : dist2[u];
- We simply check if dist1[] is visited. If yes, then we check if
  dist2[] is visted.
- Since we are using BFS, and all cost to traversing through every node is same, 
  Its guaranteed that, the first distance that we find in dits1[] is the shortest. 
- We use the same formula for finding the timePassed and check in which zone the time lies.

*/

/*

2045. Second Minimum Time to Reach Destination

A city is represented as a bi-directional connected graph with n vertices where each vertex is
labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array
edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi.
Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
The time taken to traverse any edge is time minutes.

Each vertex has a traffic signal which changes its color from green to red and vice versa every
change minutes. All signals change at the same time. You can enter a vertex at any time, but can
leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.

The second minimum value is defined as the smallest value strictly larger than the minimum value.

For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1
to vertex n.

Notes:

You can go through any vertex any number of times, including 1 and n.
You can assume that when the journey starts, all signals have just turned green.

Example 1:

Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
Output: 13
Explanation:
The figure on the left shows the given graph.
The blue path in the figure on the right is the minimum time path.
The time taken is:
- Start at 1, time elapsed=0
- 1 -> 4: 3 minutes, time elapsed=3
- 4 -> 5: 3 minutes, time elapsed=6
Hence the minimum time needed is 6 minutes.

The red path shows the path to get the second minimum time.
- Start at 1, time elapsed=0
- 1 -> 3: 3 minutes, time elapsed=3
- 3 -> 4: 3 minutes, time elapsed=6
- Wait at 4 for 4 minutes, time elapsed=10
- 4 -> 5: 3 minutes, time elapsed=13
Hence the second minimum time is 13 minutes.

Example 2:

Input: n = 2, edges = [[1,2]], time = 3, change = 2
Output: 11
Explanation:
The minimum time path is 1 -> 2 with time = 3 minutes.
The second minimum time path is 1 -> 2 -> 1 -> 2 with time = 11 minutes.

Constraints:

2 <= n <= 10^4
n - 1 <= edges.length <= min(2 * 104, n * (n - 1) / 2)
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
There are no duplicate edges.
Each vertex can be reached directly or indirectly from every other vertex.
1 <= time, change <= 10^3

*/

/*
************* Java Code **************

// Dijkstra Algo

    public static int secondMinimum(int n, int[][] edges, int time, int change) {
        int m = edges.length;
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }
        int[] dist1 = new int[n + 1];
        int[] dist2 = new int[n + 1];
        Arrays.fill(dist1, Integer.MAX_VALUE);
        Arrays.fill(dist2, Integer.MAX_VALUE);
        Queue<int[]> pq = new PriorityQueue<>((a, b)-> Integer.compare(a[0], b[0]));
        pq.offer(new int[] { 0, 1 });
        dist1[1] = 0;
        while (!pq.isEmpty()) {
            int timePassed = pq.peek()[0];
            int u = pq.peek()[1];
            pq.poll();
            if (dist2[n] != Integer.MAX_VALUE && u == n)
                return dist2[n];

            int temp = timePassed / change;
            if (temp % 2 != 0)
                timePassed = (temp + 1) * change;
            if (adj.get(u) == null)
                continue;
            for (int v : adj.get(u)) {
                int newTime = timePassed + time;
                if (dist1[v] > newTime) {
                    dist2[v] = dist1[v];
                    dist1[v] = newTime;
                    pq.offer(new int[] { timePassed + time, v });
                } else if (dist2[v] > newTime && dist1[v] != newTime) {
                    dist2[v] = newTime;
                    pq.offer(new int[] { timePassed + time, v });
                }
            }
        }
        return dist2[n];
    }

*/