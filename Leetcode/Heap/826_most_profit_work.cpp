#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - using PQ and sorting workers in decending order.
    int maxProfitAssignment3(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        // TC: O(mlogm) + O(nlogn) + O(n)
        // SC: O(m)

        int n = worker.size();
        int m = difficulty.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for (int i = 0; i < m; i++)
        {
            pq.push({profit[i], difficulty[i]});
        }
        sort(worker.begin(), worker.end(), greater<>());

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (pq.empty())
                return res;
            while (pq.top().second > worker[i])
            {
                pq.pop();
            }
            res += pq.top().first;
        }
        return res;
    }

    // Optimal - Sorting and using BS on array.
    int maxProfitAssignment2(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        // TC: O(mlogm) + O(m) + O(nlogm)
        // SC: O(m)

        int n = worker.size();
        int m = difficulty.size();
        vector<pair<int, int>> mp;
        for (int i = 0; i < m; i++)
        {
            mp.push_back({difficulty[i], profit[i]});
        }
        sort(mp.begin(), mp.end());
        int maxi = 0;
        // Optimization, by storing max profit till ith index at i.
        for (int i = 0; i < m; i++)
        {
            maxi = max(maxi, mp[i].second);
            mp[i].second = maxi;
        }

        int res = 0;
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            int idx = 0;
            int l = 0, r = m - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (mp[mid].first <= worker[i])
                {
                    maxProfit = max(maxProfit, mp[mid].second);
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            res += maxProfit;
        }
        return res;
    }

    // Optimal - Sorting both array, and then iterating.
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        // TC: O(mlogm) + O(m) + O(nlogm)
        // SC: O(m)

        int n = worker.size();
        int m = difficulty.size();
        vector<pair<int, int>> mp;
        for (int i = 0; i < m; i++)
        {
            mp.push_back({difficulty[i], profit[i]});
        }
        sort(mp.begin(), mp.end());
        sort(worker.begin(), worker.end());
        int maxProfit = 0;
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j < m && mp[j].first <= worker[i])
            {
                maxProfit = max(maxProfit, mp[j].second);
                j++;
            }
            res += maxProfit;
        }
        return res;
    }
};
int main()
{
    Solution s;
    // vector<int> difficulty = {2, 4, 6, 8, 10}, profit = {10, 20, 30, 40, 50}, worker = {4, 5, 6, 7};
    vector<int> difficulty = {85, 47, 57}, profit = {24, 66, 99}, worker = {40, 25, 25};
    cout << "Result: " << s.maxProfitAssignment2(difficulty, profit, worker) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/most-profit-assigning-work

Youtube: https://www.youtube.com/watch?v=_HptwlLP8sI

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Binary%20Search/Most%20Profit%20Assigning%20Work.cpp

algorithm:

- Brute Force Approach:

- TC = O(m*n)
- for each worker[i], find max profit by iterating through the difficulty array.
- Gives TLE.

- Optimal Approach:

-

*/

/*

826. Most Profit Assigning Work

You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with
difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if three workers attempt the same job that pays $1, then the total profit will
be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.

Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a
profit of [20,20,30,30] separately.

Example 2:

Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
Output: 0

Constraints:

n == difficulty.length
n == profit.length
m == worker.length
1 <= n, m <= 104
1 <= difficulty[i], profit[i], worker[i] <= 105

*/

/*
************* Java Code **************



*/