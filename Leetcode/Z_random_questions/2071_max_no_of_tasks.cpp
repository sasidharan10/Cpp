#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &tasks, vector<int> &workers, int pills, int strength, int mid)
    {
        multiset<int> st(workers.begin(), workers.begin() + mid);
        for (int i = mid - 1; i >= 0; i--) // O(m)
        {
            int requiredStrength = tasks[i];
            auto strongestWorker = prev(st.end());
            if (*strongestWorker >= requiredStrength)
            {
                st.erase(strongestWorker);    // log(m)
            }
            else if (pills > 0)
            {
                auto lb = st.lower_bound(requiredStrength - strength);
                if (lb == st.end())
                    return false;
                st.erase(lb);
                pills--;
            }
            else
                return false;
        }
        return true;
    }
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        //T.C : O(MLogM + NLogN + Min(M,N) ∗ Log(Min(M,N)) ∗ Log(Min(M,N))), M = tasks.size(), N = workers.size()
        //S.C : O(M)
        
        int n = tasks.size();
        int m = workers.size();
        sort(tasks.begin(), tasks.end());     // nlogn
        sort(workers.begin(), workers.end(), greater<>());  // mlogm

        int l = 0;
        int r = min(m, n);
        int res = 0;
        while (l <= r)  // logr
        {
            int mid = l + (r - l) / 2;
            if (check(tasks, workers, pills, strength, mid))
            {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> tasks = {3, 2, 1}, workers = {0, 3, 3};
    int pills = 1, strength = 1;
    cout << "Result: " << s.maxTaskAssign(tasks, workers, pills, strength) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign

Youtube: https://www.youtube.com/watch?v=7tGM7XA06MI

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Binary%20Search/Maximum%20Number%20of%20Tasks%20You%20Can%20Assign.cpp
 
algorithm:

- Optimal Approach:

- binary search + multiset

*/

/*

2071. Maximum Number of Tasks You Can Assign

You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array
tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored
in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can
only be assigned to a single task and must have a strength greater than or equal to the task's strength
requirement (i.e., workers[j] >= tasks[i]).

Additionally, you have pills magical pills that will increase a worker's strength by strength. You can
decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.

Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the
maximum number of tasks that can be completed.

Example 1:

Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
Output: 3
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 >= 1)
- Assign worker 1 to task 1 (3 >= 2)
- Assign worker 2 to task 0 (3 >= 3)

Example 2:

Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
Output: 1
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 0 (0 + 5 >= 5)

Example 3:

Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
Output: 2
Explanation:
We can assign the magical pills and tasks as follows:
- Give the magical pill to worker 0 and worker 1.
- Assign worker 0 to task 0 (0 + 10 >= 10)
- Assign worker 1 to task 1 (10 + 10 >= 15)
The last pill is not given because it will not make any worker strong enough for the last task.

Constraints:

n == tasks.length
m == workers.length
1 <= n, m <= 5 * 10^4
0 <= pills <= m
0 <= tasks[i], workers[j], strength <= 10^9

*/

/*
************* Java Code **************



*/