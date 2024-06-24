#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - Finding perfect squares less than n
    int bulbSwitch2(int n)
    {
        int i = 1;
        while (i * i <= n)
        {
            i++;
        }
        return i - 1;
    }

    // Optimal - return sqrt(n).
    int bulbSwitch(int n)
    {
        return sqrt(n);
    }
};
int main()
{
    Solution s;
    int n = 100;
    cout << "Result: " << s.bulbSwitch(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/bulb-switcher

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- lets say n = 3:

- bulbs at 0th round: [ 0, 0, 0]
- bulbs at 1st round: [ 1, 1, 1]
- bulbs at 2nd round: [ 1, 0, 1]
- bulbs at 3rd round: [ 1, 0, 0]

- hence only 1 bulb is ON.

*/

/*

319. Bulb Switcher

There are n bulbs that are initially off. You first turn on all the bulbs, then you
turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off
if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.

Example 1:

Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off].
So you should return 1 because there is only one bulb is on.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 1

Constraints:

0 <= n <= 10^9

*/

/*
************* Java Code **************

public int bulbSwitch(int n) {
        return (int)Math.sqrt(n);
    }

*/