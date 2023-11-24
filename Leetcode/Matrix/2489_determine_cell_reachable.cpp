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
                if (i == 0 && j == 0)
                    continue;
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
    int sx = 2, sy = 4, fx = 7, fy = 7, t = 6;
    // int sx = 3, sy = 1, fx = 7, fy = 3, t = 3;
    // int sx = 1, sy = 2, fx = 1, fy = 2, t = 1;
    cout << "Cell Reachable?: " << s.isReachableAtTime2(sx, sy, fx, fy, t);
    // cout << "Cell Reachable?: " << s.isReachableAtTime(sx, sy, fx, fy, t);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time

Youtube: https://www.youtube.com/watch?v=1k5-LnJlH78&t=1445s

algorithm:

- We just need to find if we can reach the target in the matrix,
  so no need to traverse through all the direction and then find if its possible.
- The minimum time required to reach the target, will be equal to the 
  max(horizontal, vertical) distance. with this itself we can determine it.
- The edge case is, we need to use the full time, that is given to us
  and at the end of the time, we should be at the target cell.
- To determine this, we put 1 base case if (horizontal == 0 && vertical == 0 && t == 1)
  which means, if we reach the target when the time is 1 or an odd, we wont 
  end in the target cell. but if we reach the target with time being a even number,
  we can reach it, as we can just go back-and-forth, until time ends, and then
  we will end at the target

*/