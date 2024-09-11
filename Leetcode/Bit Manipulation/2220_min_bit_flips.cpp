#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - using mod and division.
    int minBitFlips4(int start, int goal)
    {
        // TC: O(32)
        // SC: O(1)

        int res = 0;
        while (start > 0 || goal > 0)
        {
            if ((start % 2) != (goal % 2))
                res++;
            start /= 2;
            goal /= 2;
        }
        return res;
    }

    // Better - using right shift
    int minBitFlips3(int start, int goal)
    {
        // TC: O(32)
        // SC: O(1)

        int res = 0;
        while (start > 0 || goal > 0)
        {
            if ((start & 1) != (goal & 1))
                res++;
            start = start >> 1;
            goal = goal >> 1;
        }
        return res;
    }
    // Better - Using XOR
    int minBitFlips2(int start, int goal)
    {
        // TC: O(32)
        // SC: O(1)

        int res = 0;
        int n = start ^ goal;
        while (n > 0)
        {
            if ((n & 1) == 1)
                res++;
            n = n >> 1;
        }
        return res;
    }

    // Optimal - Using XOR (Brian Kernighan’s Algorithm)
    int minBitFlips(int start, int goal)
    {
        // TC: O(1 <= 32)  
        // SC: O(1)

        int res = 0;
        int n = start ^ goal;
        while (n > 0)
        {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    int start = 10, goal = 7;
    cout << "Result: " << s.minBitFlips(start, goal) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-bit-flips-to-convert-number

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Approach 1:
- using (start % 2) to find the last bit, and then using start = (start / 2) to
  removw the last bit.

- Approach 2:
- using (start & 1) to find the last bit, and then using start = (start >> 1) to
  removw the last bit.

- Approach 3:
- using XOR. n = (start ^ goal) will give us the total number of bits which are different.
- The no of 1's present in 'n', is the number of bits, that are different.
- Hence we just need to calculate total 1's present in 'n'.

- Approach 4:
- Similar to 3rd approach, but here we use Brian Kernighan’s Algorithm (n & (n - 1)) to 
  count total no of 1's present in 'n'.
- It's the most efficient way to count total number of 1's present in a number.
  
*/

/*

2220. Minimum Bit Flips to Convert Number

A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from
either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any
leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip
the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to
get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

Example 1:

Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10
to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.

Example 2:

Input: start = 3, goal = 4
Output: 3
Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4
in 3 steps:
- Flip the first bit from the right: 011 -> 010.
- Flip the second bit from the right: 010 -> 000.
- Flip the third bit from the right: 000 -> 100.
It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.

Constraints:

0 <= start, goal <= 10^9

*/

/*
************* Java Code **************

    public int minBitFlips(int start, int goal) {
        int res = 0;
        int n = start ^ goal;
        while (n > 0)
        {
            n = n & (n - 1);
            res++;
        }
        return res;
    }

*/