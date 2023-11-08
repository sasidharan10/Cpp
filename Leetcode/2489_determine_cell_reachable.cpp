#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute
    bool isReachableAtTime2(int sx, int sy, int fx, int fy, int t)
    {
        if (t < 0)
            return false;
        if (sx == fx && sy == fy && t == 1)
            return false;
        if (sx == fx && sy == fy && t >= 0)
            return true;
        for (int i = 1; i >= -1; i--)
        {
            for (int j = 1; j >= -1; j--)
            {
                int row = sx + i;
                int col = sy + j;
                if (isReachableAtTime(row, col, fx, fy, t - 1))
                    return true;
            }
        }
        return false;
    }
    // Optimal
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        long long horizontal = abs(fx - sx);
        long long vertical = abs(fy - sy);
        long long timeToReach = max(horizontal, vertical);
        if (horizontal == 0 && vertical == 0 && t == 1)
            return false;
        if (t >= timeToReach)
            return true;
        else
            return false;
    }
};
int main()
{
    Solution s;
    // int sx = 2, sy = 4, fx = 7, fy = 7, t = 6;
    int sx = 3, sy = 1, fx = 7, fy = 3, t = 3;
    // int sx = 1, sy = 2, fx = 1, fy = 2, t = 1;
    cout << "Cell Reachable?: " << s.isReachableAtTime(sx, sy, fx, fy, t);
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/