#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int mod = 1e9 + 7;

public:
    int numberOfWays(string corridor)
    {
        int n = corridor.length();
        vector<int> seat;
        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
                seat.push_back(i);
        }
        int m = seat.size();
        long long res = 1;
        if (m < 2 || m % 2 != 0)
            return 0;
        int prev_end_idx = seat[1];
        int len = 0;
        for (int i = 2; i < m; i += 2)
        {
            len = seat[i] - prev_end_idx;
            res = (res * len) % mod;
            prev_end_idx = seat[i + 1];
        }
        return res;
    }
};
int main()
{
    Solution s;
    string corridor = "SSPPSPS";
    cout << "Number of Ways to Divide a Long Corridor: " << s.numberOfWays(corridor) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor

Youtube: https://www.youtube.com/watch?v=ixzhJ8OoA6Q

algorithm:

- We have to divide the chairs into sections having exactly 2 chairs, hence if corridoor
  has odd no of chairs, or has less than 2 chairs, we can return 0.
- We keep track of starting and ending index in an array, then subtract (prev_end - start) index
  to get the count of ways, we can divide the 2 sections of the corridoor (each section must have 2 chairs)
- Then we multiply all this ways, to get the total no of pssible ways.

*/

/*

2147. Number of Ways to Divide a Long Corridor

Along a long library corridor, there is a line of seats and decorative plants.
You are given a 0-indexed string corridor of length n consisting of letters 'S'
and 'P' where each 'S' represents a seat and each 'P' represents a plant.

One room divider has already been installed to the left of index 0, and another
to the right of index n - 1. Additional room dividers can be installed. For each
position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can be installed.

Divide the corridor into non-overlapping sections, where each section has exactly
two seats with any number of plants. There may be multiple ways to perform the
division. Two ways are different if there is a position with a room divider
installed in the first way but not in the second way.

Return the number of ways to divide the corridor. Since the answer may be very
large, return it modulo 109 + 7. If there is no way, return 0.


Example 1:

Input: corridor = "SSPPSPS"
Output: 3
Explanation: There are 3 different ways to divide the corridor.
The black bars in the above image indicate the two room dividers already installed.
Note that in each of the ways, each section has exactly two seats.
Example 2:


Input: corridor = "PPSPSP"
Output: 1
Explanation: There is only 1 way to divide the corridor, by not installing any additional dividers.
Installing any would create some section that does not have exactly two seats.
Example 3:


Input: corridor = "S"
Output: 0
Explanation: There is no way to divide the corridor because there will
always be a section that does not have exactly two seats.

*/