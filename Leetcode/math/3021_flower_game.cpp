#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - gives TLE
    long long flowerGame(int n, int m)
    {
        // TC: O(n * m) → check every pair (i, j)
        // SC: O(1)     → no extra space

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if ((i + j) % 2 != 0) // odd sum → valid pair
                    cnt++;
            }
        }
        return cnt;
    }

    // Optimal
    long long flowerGame(int n, int m)
    {
        // TC: O(1)
        // SC: O(1)

        long long oddN = (n + 1) / 2; // count of odd numbers in 1..n
        long long evenN = n / 2;      // count of even numbers in 1..n
        long long oddM = (m + 1) / 2; // count of odd numbers in 1..m
        long long evenM = m / 2;      // count of even numbers in 1..m

        // odd + even OR even + odd = odd sum
        return oddN * evenM + evenN * oddM;
    }
};
int main()
{
    Solution s;
    int n = 3, m = 2;
    cout << "Result: " << s.flowerGame(n, m) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/alice-and-bob-playing-flower-game/

Youtube: https://www.youtube.com/watch?v=8PuV3IvUgk8

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Mathematical/Alice%20and%20Bob%20Playing%20Flower%20Game.cpp

algorithm:

- Brute Force Approach:

- We are given two ranges:
- First flower chosen from 1...n
- Second flower chosen from 1...m
- For every pair (i, j) → check if sum is odd → (i + j) % 2 != 0.
- Because only if sum is odd, then only Alice can start and finish the game.
- Count such pairs.
- Returns the total count.

- Optimal Approach:

- A pair (i, j) has an odd sum if one is odd and the other is even.
- So, count:
    - Odd numbers in 1..n → (n + 1) / 2
    - Even numbers in 1..n → n / 2
    - Odd numbers in 1..m → (m + 1) / 2
    - Even numbers in 1..m → m / 2
- Total valid pairs = oddN * evenM + evenN * oddM.
- Works in O(1) time.

*/

/*

3021. Alice and Bob Playing Flower Game

Alice and Bob are playing a turn-based game on a field, with two lanes of flowers between them. There 
are x flowers in the first lane between Alice and Bob, and y flowers in the second lane between them.

The game proceeds as follows:

Alice takes the first turn.
In each turn, a player must choose either one of the lane and pick one flower from that side.
At the end of the turn, if there are no flowers left at all in either lane, the current player captures 
their opponent and wins the game.
Given two integers, n and m, the task is to compute the number of possible pairs (x, y) that satisfy the conditions:

Alice must win the game according to the described rules.
The number of flowers x in the first lane must be in the range [1,n].
The number of flowers y in the second lane must be in the range [1,m].
Return the number of possible pairs (x, y) that satisfy the conditions mentioned in the statement.

Example 1:

Input: n = 3, m = 2
Output: 3
Explanation: The following pairs satisfy conditions described in the statement: (1,2), (3,2), (2,1).

Example 2:

Input: n = 1, m = 1
Output: 0
Explanation: No pairs satisfy the conditions described in the statement.
 
Constraints:

1 <= n, m <= 10^5

*/

/*
************* Java Code **************

    public long flowerGame(int n, int m) {
        long oddN = (n + 1) / 2;
        long evenN = n / 2;
        long oddM = (m + 1) / 2;
        long evenM = m / 2;

        // odd + even OR even + odd = odd sum
        return oddN * evenM + evenN * oddM;
    }

*/