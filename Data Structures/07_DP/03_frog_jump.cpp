#include <bits/stdc++.h>
using namespace std;
int frogJumpRecur(int index, vector<int> &heights)
{
    if (index <= 0)
        return 0;
    int oneJump = frogJumpRecur(index - 1, heights) + abs(heights[index] - heights[index - 1]);
    int twoJump = INT_MAX;
    if (index > 1)
    {
        twoJump = frogJumpRecur(index - 2, heights) + abs(heights[index] - heights[index - 2]);
    }
    return min(oneJump, twoJump);
}
int frogJumpMem(int index, vector<int> &heights, vector<int> &dp)
{
    if (index <= 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int oneJump = frogJumpMem(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int twoJump = INT_MAX;
    if (index > 1)
    {
        twoJump = frogJumpMem(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
    }
    return dp[index] = min(oneJump, twoJump);
}
int frogJumpTab(int n, vector<int> &heights)
{
    vector<int> dp1(n, -1);
    dp1[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int oneJump = dp1[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoJump = INT_MAX;
        if (i > 1)
        {
            twoJump = dp1[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp1[i] = min(oneJump, twoJump);
    }
    return dp1[n - 1];
}
int frogJumpSpc(int n, vector<int> &heights)
{
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int oneJump = prev + abs(heights[i] - heights[i - 1]);
        int twoJump = INT_MAX;
        if (i > 1)
        {
            twoJump = prev2 + abs(heights[i] - heights[i - 2]);
        }
        int cur = min(oneJump, twoJump);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    // return frogJumpRecur(n - 1, heights);
    // return frogJumpMem(n - 1, heights, dp);
    // return frogJumpTab(n, heights);
    return frogJumpSpc(n, heights);
}
int main()
{
    int n = 4;
    vector<int> height{10, 20, 30, 10};
    cout << "Least Energy spent: " << frogJump(n, height);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/frog-jump_3621012

leetcode:

Youtube: https://www.youtube.com/watch?v=EgG3jsGoPvQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=4

algorithm:

*/