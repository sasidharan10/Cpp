#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int solveRecur(int ind, int bricks, int ladders, int n, vector<int> &heights)
    {
        if (ind == n - 1)
            return ind;
        int takeBrick = ind;
        int takeLadder = ind;
        if (heights[ind + 1] <= heights[ind])
        {
            return solveRecur(ind + 1, bricks, ladders, n, heights);
        }
        else
        {
            int diff = (heights[ind + 1] - heights[ind]);
            if (bricks >= diff)
                takeBrick = solveRecur(ind + 1, bricks - diff, ladders, n, heights);
            if (ladders > 0)
                takeLadder = solveRecur(ind + 1, bricks, ladders - 1, n, heights);
        }
        return max(takeBrick, takeLadder);
    }
    // Memoization
    int solveMem(int ind, int bricks, int ladders, int n, vector<int> &heights, vector<vector<vector<int>>> &dp)
    {
        if (ind == n - 1)
            return ind;
        if (dp[ind][bricks][ladders] != -1)
            return dp[ind][bricks][ladders];
        int takeBrick = ind;
        int takeLadder = ind;
        if (heights[ind + 1] <= heights[ind])
        {
            return dp[ind][bricks][ladders] = solveMem(ind + 1, bricks, ladders, n, heights, dp);
        }
        else
        {
            int diff = (heights[ind + 1] - heights[ind]);
            if (bricks >= diff)
                takeBrick = solveMem(ind + 1, bricks - diff, ladders, n, heights, dp);
            if (ladders > 0)
                takeLadder = solveMem(ind + 1, bricks, ladders - 1, n, heights, dp);
        }
        return dp[ind][bricks][ladders] = max(takeBrick, takeLadder);
    }
    // Lazy Greedy
    int furthestBuilding2(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int> pq;
        int ind = 0;
        for (; ind < n - 1; ind++)
        {
            if (heights[ind + 1] <= heights[ind])
                continue;

            int diff = heights[ind + 1] - heights[ind];
            if (bricks >= diff)
            {
                bricks -= diff;
                pq.push(diff);
            }
            else if (ladders > 0)
            {
                if (!pq.empty())
                {
                    int max_past_brick = pq.top();
                    if (max_past_brick > diff)
                    {
                        bricks += max_past_brick;
                        pq.pop();
                        bricks -= diff;
                        pq.push(diff);
                        ladders--;
                    }
                    else
                        ladders--;
                }
                else
                    ladders--;
            }
            else
                break;
        }
        return ind;
    }
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        // int n = heights.size();
        // return solveRecur(0, bricks, ladders, n, heights);
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1)));
        // return solveMem(0, bricks, ladders, n, heights, dp);
        return furthestBuilding2(heights, bricks, ladders);
    }
};
int main()
{
    Solution s;
    vector<int> nums{4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks = 10, ladders = 2;
    cout << "Result: " << s.furthestBuilding(nums, bricks, ladders) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*






*/