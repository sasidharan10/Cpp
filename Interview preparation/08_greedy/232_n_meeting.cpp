#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second < p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // TC: O(nlogn) + O(n)
        // SC: O(n)

        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), comp);
        int count = 1;
        int ansEnd = v[0].second;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first > ansEnd)
            {
                count++;
                ansEnd = v[i].second;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = 6;
    cout << "Max Meeting in the room: " << s.maxMeetings(start, end, n);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

leetcode:

Youtube:

algorithm:

*/