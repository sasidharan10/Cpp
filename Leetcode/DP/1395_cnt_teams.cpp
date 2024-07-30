#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int numTeamsRecur(int ind, int prev, int cnt, int n, vector<int> &rating)
    {
        // TC: O(2^n)
        // SC: O(n)

        if (cnt == 3)
            return 1;
        if (ind == n)
            return 0;
        int Notpick = numTeamsRecur(ind + 1, prev, cnt, n, rating);
        int pick = 0;
        if (prev == -1 || rating[ind] > rating[prev])
            pick = numTeamsRecur(ind + 1, ind, cnt + 1, n, rating);
        return pick + Notpick;
    }
    int numTeamsRecurDecr(int ind, int prev, int cnt, int n, vector<int> &rating)
    {
        if (cnt == 3)
            return 1;
        if (ind == n)
            return 0;
        int Notpick = numTeamsRecurDecr(ind + 1, prev, cnt, n, rating);
        int pick = 0;
        if (prev == -1 || rating[ind] < rating[prev])
            pick = numTeamsRecurDecr(ind + 1, ind, cnt + 1, n, rating);
        return pick + Notpick;
    }

    // Memoization

    // int dp[1002][1002][4]; // normal compiler doesn't work, but works well LC compiler.
    int dp[100][100][4]; // reduced capacity, to make this program run.
    int numTeamsMem(int ind, int prev, int cnt, int n, vector<int> &rating)
    {
        // TC: O(n*n*4)
        // SC: O(n) + O(n) Stack space

        if (cnt == 3)
            return 1;
        if (ind == n)
            return 0;
        if (dp[ind][prev + 1][cnt] != -1)
            return dp[ind][prev + 1][cnt];
        int Notpick = numTeamsMem(ind + 1, prev, cnt, n, rating);
        int pick = 0;
        if (prev == -1 || rating[ind] > rating[prev])
            pick = numTeamsMem(ind + 1, ind, cnt + 1, n, rating);
        return dp[ind][prev + 1][cnt] = pick + Notpick;
    }
    int numTeamsMemDecr(int ind, int prev, int cnt, int n, vector<int> &rating)
    {
        if (cnt == 3)
            return 1;
        if (ind == n)
            return 0;
        if (dp[ind][prev + 1][cnt] != -1)
            return dp[ind][prev + 1][cnt];
        int Notpick = numTeamsMemDecr(ind + 1, prev, cnt, n, rating);
        int pick = 0;
        if (prev == -1 || rating[ind] < rating[prev])
            pick = numTeamsMemDecr(ind + 1, ind, cnt + 1, n, rating);
        return dp[ind][prev + 1][cnt] = pick + Notpick;
    }

    // Brute force - Using DP
    int numTeams2(vector<int> &rating)
    {
        // TC: O(n*n*4)
        // SC: O(n) + O(n) Stack space
        
        int n = rating.size();
        // int incr = numTeamsRecur(0, -1, 0, n, rating);
        // int decr = numTeamsRecurDecr(0, -1, 0, n, rating);

        memset(dp, -1, sizeof(dp));
        int incr = numTeamsMem(0, -1, 0, n, rating);
        memset(dp, -1, sizeof(dp));
        int decr = numTeamsMemDecr(0, -1, 0, n, rating);
        return incr + decr;
    }
    // Finding strictly increasing sequence
    int solve1(vector<int> &rating)
    {
        int n = rating.size();
        int cnt = 0;
        for (int j = 1; j < n - 1; j++)
        {
            int lt = 0, rt = 0;
            for (int i = 0; i < j; i++)
            {
                if (rating[i] < rating[j])
                    lt++;
            }
            for (int k = j + 1; k < n; k++)
            {
                if (rating[k] > rating[j])
                    rt++;
            }
            cnt += lt * rt;
        }
        return cnt;
    }
    // Finding strictly decreasing sequence
    int solve2(vector<int> &rating)
    {
        int n = rating.size();
        int cnt = 0;
        for (int j = 1; j < n - 1; j++)
        {
            int lt = 0, rt = 0;
            for (int i = 0; i < j; i++)
            {
                if (rating[i] > rating[j])
                    lt++;
            }
            for (int k = j + 1; k < n; k++)
            {
                if (rating[k] < rating[j])
                    rt++;
            }
            cnt += lt * rt;
        }
        return cnt;
    }
    // Optimal - Finding no of sequence by keeping j as center element.
    int numTeams(vector<int> &rating)
    {
        // TC: O(n^2)
        // SC: O(1)

        int incr = solve1(rating);
        int decr = solve2(rating);
        return incr + decr;
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 5, 3, 4, 1};
    cout << "Result: " << s.numTeams(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-number-of-teams

Youtube: https://www.youtube.com/watch?v=UZupIKXnzq8

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Count%20Number%20of%20Teams.cpp

algorithm:

- Brute Force Approach:

- Using DP and then Memoizing the solution using 3D array.

- Optimal Approach:

- 
- For find no of strictly increaseing sequence, we take every element in the array as the center 
  of the sequence.
- Then we find the no of elements present in left side which are strictly less than the 
  middle element. let's say its called as lt.
- Then we find the no of elements present in right side which are strictly greater than the 
  middle element. let's say its called as rt.
- The total number of sequence that an be formed, by the jth as middle = lt * rt.
- We do this for all possible j values.
- Similarly, we check for strictly decreasing sequence by applying the same logic.
- Then return the sum of both.

*/

/*

1395. Count Number of Teams

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k])
where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).

Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:

Input: rating = [1,2,3,4]
Output: 4

*/

/*
************* Java Code **************

public static int solve1(int[] rating) {
        int n = rating.length;
        int cnt = 0;
        for (int j = 1; j < n - 1; j++) {
            int lt = 0, rt = 0;
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j])
                    lt++;
            }
            for (int k = j + 1; k < n; k++) {
                if (rating[k] > rating[j])
                    rt++;
            }
            cnt += lt * rt;
        }
        return cnt;
    }

    public static int solve2(int[] rating) {
        int n = rating.length;
        int cnt = 0;
        for (int j = 1; j < n - 1; j++) {
            int lt = 0, rt = 0;
            for (int i = 0; i < j; i++) {
                if (rating[i] > rating[j])
                    lt++;
            }
            for (int k = j + 1; k < n; k++) {
                if (rating[k] < rating[j])
                    rt++;
            }
            cnt += lt * rt;
        }
        return cnt;
    }

    public static int numTeams(int[] rating) {
        // TC: O(n^2)
        // SC: O(1)

        int incr = solve1(rating);
        int decr = solve2(rating);
        return incr + decr;
    }

*/