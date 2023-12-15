#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        int n = paths.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string from = paths[i][0];
            string to = paths[i][1];
            mp[from]++;
            if (!mp[to])
                mp[to] = 0;
        }
        for (auto it : mp)
        {
            if (it.second == 0)
                return it.first;
        }
        return "";
    }
};
int main()
{
    Solution s;
    vector<vector<string>> paths{{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    cout << "City with OutDegree 0: " << s.destCity(paths) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/destination-city

Youtube:

algorithm:

- We use a map, to store its outDegree, and then iterate through it, to find the
  city with 0 outDegree.

*/

/*






*/