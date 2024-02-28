#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    vector<int> findAllPeople4(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        // TC: O(m) * O(m + n)
        // SC: O(m + n) + O(m) + O(n)

        int m = meetings.size();
        map<int, vector<pair<int, int>>> timeMeetings;
        for (int i = 0; i < m; i++)
        {
            int person1 = meetings[i][0];
            int person2 = meetings[i][1];
            int time = meetings[i][2];

            timeMeetings[time].push_back({person1, person2});
        }

        vector<bool> knowSecret(n, false);
        knowSecret[0] = true;
        knowSecret[firstPerson] = true;

        for (auto &&it : timeMeetings)
        {
            int time = it.first;
            vector<pair<int, int>> meets = it.second;
            unordered_map<int, vector<int>> adj; // a -> {b ,c ,d}
            unordered_set<int> alreadyAdded;
            queue<int> que;

            for (auto &&mt : meets)
            {
                int person1 = mt.first;
                int person2 = mt.second;

                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                if (knowSecret[person1] && alreadyAdded.find(person1) == alreadyAdded.end())
                {
                    que.push(person1);
                    alreadyAdded.insert(person1);
                }

                if (knowSecret[person2] && alreadyAdded.find(person2) == alreadyAdded.end())
                {
                    que.push(person2);
                    alreadyAdded.insert(person2);
                }
            }

            while (!que.empty())
            {
                int person1 = que.front();
                que.pop();
                for (auto &&p2 : adj[person1])
                {
                    if (!knowSecret[p2])
                    {
                        knowSecret[p2] = true;
                        que.push(p2);
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (knowSecret[i] == true)
                ans.push_back(i);
        }
        return ans;
    }

    // better - BFS
    vector<int> findAllPeople3(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        int m = meetings.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < m; i++)
        {
            int person1 = meetings[i][0];
            int person2 = meetings[i][1];
            int time = meetings[i][2];

            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        vector<int> knowSecret(n, 1e9);
        knowSecret[0] = 0;
        knowSecret[firstPerson] = 0;
        queue<pair<int, int>> que;
        que.push({0, 0});
        que.push({firstPerson, 0});

        while (!que.empty())
        {
            int person = que.front().first;
            int time = que.front().second;
            que.pop();
            for (auto &&it : adj[person])
            {
                int nextPerson = it.first;
                int t = it.second;

                if (t >= time && t < knowSecret[nextPerson])
                {
                    knowSecret[nextPerson] = t;
                    que.push({nextPerson, t});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (knowSecret[i] != 1e9)
                ans.push_back(i);
        }
        return ans;
    }

    // better - DFS
    void dfs(int node, int time, unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &knowSecret)
    {
        knowSecret[node] = time;
        for (auto &&it : adj[node])
        {
            int nextPerson = it.first;
            int t = it.second;

            if (t >= time && t < knowSecret[nextPerson])
            {
                dfs(nextPerson, t, adj, knowSecret);
            }
        }
    }
    vector<int> findAllPeople2(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        int m = meetings.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < m; i++)
        {
            int person1 = meetings[i][0];
            int person2 = meetings[i][1];
            int time = meetings[i][2];

            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        vector<int> knowSecret(n, 1e9);
        knowSecret[0] = 0;
        knowSecret[firstPerson] = 0;

        dfs(0, 0, adj, knowSecret);
        dfs(firstPerson, 0, adj, knowSecret);

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (knowSecret[i] != 1e9)
                ans.push_back(i);
        }
        return ans;
    }

    // Optimal
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        int m = meetings.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < m; i++)
        {
            int person1 = meetings[i][0];
            int person2 = meetings[i][1];
            int time = meetings[i][2];

            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        while (!pq.empty())
        {
            int time = pq.top().first;
            int person = pq.top().second;
            pq.pop();

            if (vis[person])
                continue;
            vis[person] = true;
            for (auto &&it : adj[person])
            {
                int nextPerson = it.first;
                int t = it.second;

                if (t >= time && !vis[nextPerson])
                {
                    pq.push({t, nextPerson});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 4, firstPerson = 3;
    vector<vector<int>> nums{{3, 1, 3}, {1, 2, 2}, {0, 3, 3}};
    vector<int> ans = s.findAllPeople(n, nums, firstPerson);
    cout << "People who Know Secret: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-all-people-with-secret/

Youtube: https://www.youtube.com/watch?v=hxEWwnJJKcY

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*






*/