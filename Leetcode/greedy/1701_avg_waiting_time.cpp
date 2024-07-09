#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        // TC: O(n)
        // SC: O(1)
        
        double n = customers.size();
        int curTime = customers[0][0];
        double totalTime = 0;
        int startTime, endTime, duration;
        for (int i = 0; i < n; i++)
        {
            startTime = customers[i][0];
            duration = customers[i][1];
            if (curTime > startTime)
            {
                curTime += duration;
                totalTime += curTime - startTime;
            }
            else
            {
                curTime = startTime + duration;
                totalTime += duration;
            }
        }
        return totalTime / n;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> nums{{5, 2}, {5, 4}, {10, 3}, {20, 1}};
    // vector<vector<int>> nums{{1, 2}, {2, 5}, {4, 3}};
    vector<vector<int>> nums{{2, 3}, {6, 3}, {7, 5}, {11, 3}, {15, 2}, {18, 1}};
    cout << "Result: " << s.averageWaitingTime(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/average-waiting-time

Youtube: https://www.youtube.com/watch?v=g7P8Zkq8P9Q

Code Link:

algorithm:

- Optimal Approach:

- We keep track of curTIme.
- If curTime > startTime, then the customer has to wait until starttime + duration(time to cook).
- But if curTime <= startTIme, then the customer does not have to wait until starttime,
  he just neeeds to wait for the duration(time to cook).
  
*/

/*

1701. Average Waiting Time

There is a restaurant with a single chef. You are given an array customers, where 
customers[i] = [arrivali, timei]:

arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
timei is the time needed to prepare the order of the ith customer.
When a customer arrives, he gives the chef his order, and the chef starts preparing it 
once he is idle. The customer waits till the chef finishes preparing his order. The chef 
does not prepare food for more than one customer at a time. The chef prepares food for 
customers in the order they were given in the input.

Return the average waiting time of all customers. Solutions within 10-5 from the actual 
answer are considered accepted.

Example 1:

Input: customers = [[1,2],[2,5],[4,3]]
Output: 5.00000
Explanation:
1) The first customer arrives at time 1, the chef takes his order and starts preparing 
it immediately at time 1, and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
2) The second customer arrives at time 2, the chef takes his order and starts preparing 
it at time 3, and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
3) The third customer arrives at time 4, the chef takes his order and starts preparing 
it at time 8, and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
So the average waiting time = (2 + 6 + 7) / 3 = 5.

Example 2:

Input: customers = [[5,2],[5,4],[10,3],[20,1]]
Output: 3.25000
Explanation:
1) The first customer arrives at time 5, the chef takes his order and starts preparing 
it immediately at time 5, and finishes at time 7, so the waiting time of the first 
customer is 7 - 5 = 2.
2) The second customer arrives at time 5, the chef takes his order and starts preparing 
it at time 7, and finishes at time 11, so the waiting time of the second customer is 11 - 5 = 6.
3) The third customer arrives at time 10, the chef takes his order and starts preparing 
it at time 11, and finishes at time 14, so the waiting time of the third customer is 14 - 10 = 4.
4) The fourth customer arrives at time 20, the chef takes his order and starts preparing 
it immediately at time 20, and finishes at time 21, so the waiting time of the fourth 
customer is 21 - 20 = 1.
So the average waiting time = (2 + 6 + 4 + 1) / 4 = 3.25.
 
Constraints:

1 <= customers.length <= 10^5
1 <= arrival[i], time[i] <= 10^4
arrival[i] <= arrival[i+1]

*/

/*
************* Java Code **************

public double averageWaitingTime(int[][] customers) {
        double n = customers.length;
        int curTime = customers[0][0];
        double totalTime = 0;
        int startTime, endTime, duration;
        for (int i = 0; i < n; i++)
        {
            startTime = customers[i][0];
            duration = customers[i][1];
            if (curTime > startTime)
            {
                curTime += duration;
                totalTime += curTime - startTime;
            }
            else
            {
                curTime = startTime + duration;
                totalTime += duration;
            }
        }
        return totalTime / n;
    }

*/