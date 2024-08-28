#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        // T.C: O(E*log(V))
        // S.C: O(V + E)
        unordered_map<int, vector<pair<int, double>>> mp;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            mp[u].push_back({v, wt});
            mp[v].push_back({u, wt});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});
        while (!pq.empty())
        {
            double prob = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (u == end_node)
                return prob;
            for (auto &&it : mp[u])
            {
                int v = it.first;
                double p = it.second;
                if (prob * p > dist[v])
                {
                    dist[v] = prob * p;
                    pq.push({dist[v], v});
                }
            }
        }
        return 0.0;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
    int n = 3, start_node = 0, end_node = 2;
    vector<double> succProb{0.5, 0.5, 0.3};
    cout << "Result: " << s.maxProbability(n, edges, succProb, start_node, end_node) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/path-with-maximum-probability/description/

Youtube: https://www.youtube.com/watch?v=zTM9k6jqpXI

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra'a%20Based%20Problems/Path%20with%20Maximum%20Probability.cpp

- Optimal Approach:

- using Dijkstra Algorithm.
- Initially the probability of the source is 1.
- As we traverse through the path, we haave to multiply the success probability.
- To find the path with max probability, we need to modify the dijkstra algo, 
  by proiritising path with max probability.
- hence we use a max-heap and update the dist[] if we find max paths.

*/

/*

1514. Path with Maximum Probability

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list 
where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability 
of success of traversing that edge succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from 
start to end and return its success probability.
If there is no path from start to end, return 0. Your answer will be accepted if it differs from 
the correct answer by at most 1e-5.

Example 1:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 
and the other has 0.5 * 0.5 = 0.25.

Example 2:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:

Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 
Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.

*/

/*   
************* Java Code **************

    public static double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        Map<Integer, List<double[]>> mp = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            mp.computeIfAbsent(u, k -> new ArrayList<>()).add(new double[] { v, wt });
            mp.computeIfAbsent(v, k -> new ArrayList<>()).add(new double[] { u, wt });
        }

        PriorityQueue<double[]> pq = new PriorityQueue<>(new Comparator<double[]>() {
            public int compare(double[] a, double[] b) {
                return Double.compare(b[0], a[0]);
            }
        });
        double[] dist = new double[n];
        Arrays.fill(dist, 0.0);
        dist[start_node] = 1.0;
        pq.offer(new double[] { 1.0, start_node });
        while (!pq.isEmpty()) {
            double prob = pq.peek()[0];
            int u = (int) pq.peek()[1];
            pq.poll();
            if (u == end_node)
                return prob;
            if (mp.get(u) == null)
                continue;
            for (double[] it : mp.get(u)) {
                int v = (int) it[0];
                double p = it[1];
                if (prob * p > dist[v]) {
                    dist[v] = prob * p;
                    pq.offer(new double[] { dist[v], v });
                }
            }
        }
        return 0.0;
    }

*/