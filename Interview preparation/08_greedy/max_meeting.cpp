#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
    {
        return p1.second.second < p2.second.second;
    }
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
    {
        // TC: O(2nlogn) + O(n)
        // SC: O(n)

        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < N; i++)
        {
            v.push_back({i + 1, {S[i], F[i]}});
        }
        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        ans.push_back(v[0].first);
        int ansEnd = v[0].second.second;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].second.first > ansEnd)
            {
                ans.push_back(v[i].first);
                ansEnd = v[i].second.second;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> start{1, 3, 0, 5, 8, 5};
    vector<int> end{2, 4, 6, 7, 9, 9};
    int n = 6;
    cout << "Max Meeting in the room: " << endl;
    vector<int> ans = s.maxMeetings(n, start, end);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

leetcode:

Youtube:

algorithm:

*/