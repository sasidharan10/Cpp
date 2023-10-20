#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto &&node : adj[i])
            {
                inDegree[node]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
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
        return ans.size() == numCourses;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> prerequisites{{1, 0}, {2, 1}, {3, 2}};
    int n = 4;
    cout << "Possible to complete task: " << s.canFinish(n, prerequisites);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

leetcode: https://leetcode.com/problems/course-schedule/

Youtube: https://www.youtube.com/watch?v=WAOfKpxYHR8

algorithm:

*/