#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<double> time;
        for (int i = 0; i < n; i++)
        {
            time.push_back((double)dist[i] / (double)speed[i]);
        }
        sort(time.begin(), time.end());
        int curTime = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (time[i] <= curTime)
                break;
            else
            {
                curTime++;
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    // vector<int> dist = {3, 2, 4}, speed = {5, 3, 2};
    vector<int> dist = {1, 3, 4}, speed = {1, 1, 1};
    // vector<int> dist = {1, 1, 2, 3}, speed = {1, 1, 1, 1};
    cout << "Max no of Monsters that an be eliminated: " << s.eliminateMaximum(dist, speed);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/eliminate-maximum-number-of-monsters

Youtube: https://www.youtube.com/watch?v=ShTm_qEgZ0E

algorithm:

*/