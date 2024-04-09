#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int timeRequiredToBuy3(vector<int> &tickets, int k)
    {
        // TC: O(n * 100)
        // SC: O(1)

        int n = tickets.size();
        int ans = 0;
        int t = 100;
        while (t > 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == k && tickets[i] == 1)
                    return ans + 1;
                if (tickets[i] == 0)
                    continue;
                else
                {
                    ans++;
                    tickets[i] -= 1;
                }
            }
            t--;
        }
        return ans;
    }

    // Optimal
    int timeRequiredToBuy2(vector<int> &tickets, int k)
    {
        // TC: O(n)
        // SC: O(1)

        int n = tickets.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i <= k)     // if ticket appears before k
            {
                if (tickets[i] <= tickets[k]) 
                    ans += tickets[i];
                else
                    ans += tickets[k];
            }
            else           // appears after k
            {
                if (tickets[i] <= tickets[k] - 1)
                    ans += tickets[i];
                else
                    ans += tickets[k] - 1;
            }
        }
        return ans;
    }
    // Same code, more clean
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        // TC: O(n)
        // SC: O(1)

        int n = tickets.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i <= k)
                ans += min(tickets[i], tickets[k]);
            else
                ans += min(tickets[i], tickets[k] - 1);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 3, 2};
    int k = 2;
    cout << "Result: " << s.timeRequiredToBuy(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/time-needed-to-buy-tickets/

Youtube: https://www.youtube.com/watch?v=cVmS9N6kf2Y

Code Link:

algorithm:

- Brute Force Approach:

- We traverse the array n no of times, until the k becomes 0.
- As we decrement the values, if any ticket[i] becomes 0, we ignore it.
- finally return ans.

- Optimal Approach:

- We have 2 cases here. 

- When ticket[i] appears before index k:
- If (tickets[i] <= tickets[k]), then ans += tickets[i].
- If value is bigger than ticket[k], then ans += tickets[k], because
  at max, we will traverse only ticket[k] times.
- lets say ticket[k] == 3, which means at max, we only need to traverse the array 3 times
  to make it 0.

- When ticket[i] appears after index k:
- If (tickets[i] <= tickets[k]), then ans += tickets[i].
- If value is bigger than ticket[k], then ans += tickets[k] - 1, because
  We will end traversing the array, as soon as tickets[k] becomes 0, hence
  whichever element is lying after k, won't be traversed in that last cycle, 
  hence we subtract 1 from the ans.
  
*/

/*

2073. Time Needed to Buy Tickets

There are n people in a line queuing to buy tickets, where the 0th person is at the
front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets
that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a
time and has to go back to the end of the line (which happens instantaneously) in order
to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person at position k (0-indexed) to finish buying tickets.

Example 1:

Input: tickets = [2,3,2], k = 2
Output: 6
Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.

Example 2:

Input: tickets = [5,1,1,1], k = 0
Output: 8
Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.

*/

/*
************* Java Code **************



*/