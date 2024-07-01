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

Youtube: https://www.youtube.com/watch?v=q-7aoEILGb0

Code Link:

algorithm:

- Optimal Approach:

- lets say n = 3:

- bulbs at 0th round: [ 0, 0, 0]
- bulbs at 1st round: [ 1, 1, 1]
- bulbs at 2nd round: [ 1, 0, 1]
- bulbs at 3rd round: [ 1, 0, 0]

- hence only 1 bulb is ON.

- Lets say n = 20.
- Now we will note down all the unique factors of numbers from 1 - 20.
- 1  = [1]                  => 1 
- 2  = [1, 2]               => 2
- 3  = [1, 3]               => 2
- 4  = [1, 2, 4]            => 3
- 5  = [1, 5]               => 2
- 6  = [1, 2, 3, 6]         => 4
- 7  = [1, 7]               => 2
- 8  = [1, 2, 4, 8]         => 4
- 9  = [1, 3, 9]            => 3
- 10 = [1, 2, 5, 10]        => 4
- 11 = [1, 11]              => 2
- 12 = [1, 2, 3, 4, 6, 12]  => 6
- 13 = [1, 13]              => 2
- 14 = [1, 2, 7, 14]        => 4
- 15 = [1, 3, 5, 14]        => 4
- 16 = [1, 2, 4, 8, 16]     => 5
- 17 = [1, 17]              => 2
- 18 = [1, 2, 3, 6, 9, 18]  => 6
- 19 = [1, 19]              => 2
- 20 = [1, 2, 4, 5, 10, 20] => 6

- The numbers having odd numbers of unique factors will have the bulb ON and OFF, if even.
- So All prime numbers will have only 2 factors, hence OFF.
- Only perfect square numbers have ODD no of factors, hence bulb is ON (1, 4, 9, 16).
- Either we can run aloop from 1 - n, and find total perfect squares from it.
- Or we can just return the sqrt(n), which is the same as above.

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

So you should return 1 because there is only one bulb that is ON.

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