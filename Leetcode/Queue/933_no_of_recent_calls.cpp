#include <bits/stdc++.h>
using namespace std;
class RecentCounter
{
    queue<int> q;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000)
        {
            q.pop();
        }
        return q.size();
    }
};
int main()
{
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-recent-calls

Youtube: https://www.youtube.com/watch?v=HlmNEfcgyjM

algorithm:

- The input t will be strictly increasing.
- For every request, we need to return the no of requests
  in the range (t, t - 3000). Hence we push the current
  request in the queue and then pop the elements
  which are < t - 3000. and return q.size().

*/

/*

933. Number of Recent Calls

You have a RecentCounter class which counts the number of recent
requests within a certain time frame.

Implement the RecentCounter class:

RecentCounter() Initializes the counter with zero recent requests.
int ping(int t) Adds a new request at time t, where t represents some
time in milliseconds, and returns the number of requests that has happened
in the past 3000 milliseconds (including the new request). Specifically,
return the number of requests that have happened in the inclusive range [t - 3000, t].
It is guaranteed that every call to ping uses a strictly larger
value of t than the previous call.

Example 1:

Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]

Explanation
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3

*/