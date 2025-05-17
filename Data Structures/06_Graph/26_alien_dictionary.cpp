#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.length(), s2.length());
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        // Topo sort
        vector<int> inDegree(K, 0);
        for (int i = 0; i < K; i++)
        {
            for (int node : adj[i])
            {
                inDegree[node]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < K; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        string ans = "";
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back((char)(node + 'a'));
            for (int adjacentNode : adj[node])
            {
                inDegree[adjacentNode]--;
                if (inDegree[adjacentNode] == 0)
                {
                    q.push(adjacentNode);
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    string ans = s.findOrder(dict, N, K);
    cout << "Result: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1

leetcode:

Youtube: https://www.youtube.com/watch?v=U3N_je7tWAs&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=26

algorithm:

*/