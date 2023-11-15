#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        if (start == end)
            return 0;
        int mod = 100000;
        int n = arr.size();
        queue<pair<int, int>> q;
        vector<int> dist(100000, 1e9);
        q.push({start, 0});
        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for (auto &&it : arr)
            {
                int num = (it * node) % mod;
                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;
                    if (num == end)
                        return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> arr{2, 5, 7};
    // 9 12 18 19
    // 5 5
    int start = 3, end = 30;
    cout << "Minimum Multiplications to reach End: " << s.minimumMultiplications(arr, start, end) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/