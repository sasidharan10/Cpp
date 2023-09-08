#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long minCost(long long arr[], long long n)
    {
        long long cost = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);
        while (pq.size() > 1)
        {
            long long t1 = pq.top();
            pq.pop();
            long long t2 = pq.top();
            pq.pop();
            cost += (t1 + t2);
            pq.push(t1 + t2);
        }
        pq.pop();
        return cost;
    }
};
int main()
{
    Solution s;
    long long nums[]{4, 3, 2, 6};
    long long n = 4;
    cout << "Min cost to join ropes: " << s.minCost(nums, n);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

leetcode: 

Youtube: 

algorithm: 

*/