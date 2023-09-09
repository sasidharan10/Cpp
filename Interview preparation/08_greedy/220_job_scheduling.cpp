#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
class Solution
{
public:
    static bool cmp(Job i1, Job i2)
    {
        return i1.profit > i2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);
        int maxDeadline = INT_MIN;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i].profit << endl;
        // }
        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        int maxProfit = 0;
        int jobCount = 0;
        vector<int> scheduling(maxDeadline + 1, -1);
        for (int i = 0; i < n; i++)
        {
            int currId = arr[i].id;
            int currDead = arr[i].dead;
            int currProfit = arr[i].profit;
            if (scheduling[currDead] == -1)
            {
                maxProfit += currProfit;
                jobCount++;
                scheduling[currDead] = currId;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << scheduling[i] << endl;
        }
        vector<int> ans;
        ans.push_back(jobCount);
        ans.push_back(maxProfit);
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 5;
    Job j[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    vector<int> ans = s.JobScheduling(j, n);
    cout << "No of jobs: " << ans[0] << "\nProfit: " << ans[1] << endl;
    return 0;
}