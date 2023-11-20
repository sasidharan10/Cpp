#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int time = 0, mi = 0, gi = 0, pi = 0;
        int n = garbage.size();
        int k = travel.size();
        for (int i = 0; i < n; i++)
        {
            int m = garbage[i].length();
            for (int j = 0; j < m; j++)
            {
                if (garbage[i][j] == 'M')
                    mi = i;

                else if (garbage[i][j] == 'G')
                    gi = i;

                else if (garbage[i][j] == 'P')
                    pi = i;
                time++;
            }
        }
        for (int i = 1; i < k; i++)
        {
            travel[i] += travel[i - 1];
        }
        int ans = time;
        if (gi > 0)
            ans += travel[gi - 1];
        if (mi > 0)
            ans += travel[mi - 1];
        if (pi > 0)
            ans += travel[pi - 1];
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> garbage{"MMM", "PGM", "GP"};
    vector<int> travel{3, 10};
    cout << "Minimum Amount of Time to Collect Garbage: " << s.garbageCollection(garbage, travel) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

Youtube: https://www.youtube.com/watch?v=SGJMTu9SZHs

algorithm:

- Total time taken to take each garbage is 1, so we will increment time
  by 1, everytime, we getany of the 1 garbage.
- Find the maximum index until which each truck need to go,
  then using prefix sum, we just add the time taken by each truck
  to reach to collect the garbage.
- We dont need to visit further house, if we dont find have any garbage
  present further of that type. so no need to travel time for that truck,
  since it didnt need to travel.
*/