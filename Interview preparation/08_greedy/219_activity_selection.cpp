#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), cmp);
        int count = 1;
        int ansEnd = v[0].second;
        for (int i = 1; i < v.size(); i++)
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
    int n = 4;
    vector<int> start{1, 3, 2, 5};
    vector<int> end{2, 4, 3, 6};
    cout << "Max activity: " << s.activitySelection(start, end, n) << endl;
    return 0;
}