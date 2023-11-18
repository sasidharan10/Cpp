#include <bits/stdc++.h>
using namespace std;
int ninjaTrainingRecur(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
                maxi = max(maxi, points[day][task]);
        }
        return maxi;
    }
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + ninjaTrainingRecur(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}
// Memoization
int ninjaTrainingMem(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
                maxi = max(maxi, points[day][task]);
        }
        return maxi;
    }
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + ninjaTrainingMem(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}
// Tabulation
int ninjaTrainingTab(int n, vector<vector<int>> &points)
{
    // TC: O(n * 4 * 3)
    // SC: O(n * 4)

    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][1], points[0][2], points[0][3]});
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}
// Tabulation traversing in reverse
int ninjaTrainingTab2(int n, vector<vector<int>> &points)
{
    // TC: O(n * 4 * 3)
    // SC: O(n * 4)

    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[n - 1][0] = max(points[n - 1][1], points[n - 1][2]);
    dp[n - 1][1] = max(points[n - 1][0], points[n - 1][2]);
    dp[n - 1][2] = max(points[n - 1][0], points[n - 1][1]);
    dp[n - 1][3] = max({points[n - 1][1], points[n - 1][2], points[n - 1][3]});
    for (int day = n - 2; day >= 0; day--)
    {
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day + 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[0][3];
}
// Space Optimization
int ninjaTrainingSpc(int n, vector<vector<int>> &points)
{
    // TC: O(n * 4 * 3)
    // SC: O(4)

    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][1], points[0][2], points[0][3]});
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // return ninjaTrainingRecur(n - 1, 3, points);
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // return ninjaTrainingMem(n - 1, 3, points, dp);
    // return ninjaTrainingTab(n, points);
    return ninjaTrainingTab2(n, points);
    // return ninjaTrainingSpc(n, points);
}
int main()
{
    vector<vector<int>> points{{10, 40, 70},
                               {20, 50, 80},
                               {30, 60, 90}};
    int n = 3;
    cout << "Maximum points: " << ninjaTraining(n, points) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/ninja-s-training_3621003

leetcode:

Youtube:

algorithm:

*/