#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    long long solve(int ind, int n, vector<vector<int>> &questions)
    {
        if (ind >= n)
        {
            return 0;
        }
        long long take = questions[ind][0] + solve(ind + questions[ind][1] + 1, n, questions);
        long long notTake = solve(ind + 1, n, questions);
        return max(take, notTake);
    }

    // Memoization
    long long solveMem(int ind, int n, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if (ind >= n)
        {
            return 0;
        }
        if (dp[ind] != -1)
            return dp[ind];
        long long take = questions[ind][0] + solveMem(ind + questions[ind][1] + 1, n, questions, dp);
        long long notTake = solveMem(ind + 1, n, questions, dp);
        return dp[ind] = max(take, notTake);
    }

    // Tabulation
    long long solveTab(int n, vector<vector<int>> &questions)
    {
        if (n == 1)
            return questions[0][0];
        vector<long long> dp(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            long long nextIdx = (i + questions[i][1] + 1) >= n ? 0 : (i + questions[i][1] + 1);
            long long nextIdx2 = (i + 1) >= n ? 0 : (i + 1);
            dp[i] = max(questions[i][0] + dp[nextIdx], dp[nextIdx2]);
        }
        return dp[0];
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n, -1);
        // return solve(0, n, questions);
        // return solveMem(0, n, questions, dp);
        return solveTab(n, questions);
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    cout << "Result: " << s.mostPoints(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/solving-questions-with-brainpower

Youtube: https://www.youtube.com/watch?v=NcC8lo7nLCE

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Solving%20Questions%20With%20Brainpower.cpp

algorithm:

- Optimal Approach:

- dp

*/

/*

2140. Solving Questions With Brainpower

You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e.,
starting from question 0) and make a decision whether to solve or skip each question. Solving question i
will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If
you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable
to solve questions 2 and 3.
Return the maximum points you can earn for the exam.

Example 1:

Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

Example 2:

Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.

Constraints:

1 <= questions.length <= 10^5
questions[i].length == 2
1 <= pointsi, brainpoweri <= 10^5

*/

/*
************* Java Code **************

    public static long solveMem(int ind, int n, int[][] questions, long[] dp)
    {
        if (ind >= n)
        {
            return 0;
        }
        if (dp[ind] != -1)
            return dp[ind];
        long take = questions[ind][0] + solveMem(ind + questions[ind][1] + 1, n, questions, dp);
        long notTake = solveMem(ind + 1, n, questions, dp);
        return dp[ind] = Math.max(take, notTake);
    }

    public static long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] dp = new long[n];
        Arrays.fill(dp, -1);
        return solveMem(0, n, questions, dp);
    }

*/