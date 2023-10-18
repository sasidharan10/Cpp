#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        vector<int> adj[N];
        for (int i = 0; i < P; i++)
        {
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> inDegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (auto &&node : adj[i])
            {
                inDegree[node]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto &&i : adj[node])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return ans.size() == N;
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // TC:  O(V+E)
        // SC: O(2n)

        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto &&node : adj[i])
            {
                inDegree[node]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto &&i : adj[node])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<pair<int, int>> prerequisites{{1, 0}, {2, 1}, {3, 2}};
    int N = 4;
    int V = 3;
    cout << "Possible to complete task: " << s.isPossible(N, V, prerequisites);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

leetcode:

Youtube: https://www.youtube.com/watch?v=WAOfKpxYHR8

algorithm:

*/