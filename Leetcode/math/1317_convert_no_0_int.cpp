#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool noZeroCheck(int num1, int num2)
    {
        // Check each digit of num1
        while (num1 > 0)
        {
            int rem = num1 % 10;
            if (rem == 0) // if any digit is 0 → not valid
                return false;
            num1 /= 10;
        }

        // Check each digit of num2
        while (num2 > 0)
        {
            int rem = num2 % 10;
            if (rem == 0) // if any digit is 0 → not valid
                return false;
            num2 /= 10;
        }

        // Both numbers have no zero digits
        return true;
    }

    // Brute force
    vector<int> getNoZeroIntegers2(int n)
    {
        // TC: O(n)
        // SC: O(1)

        vector<int> ans;

        // Try every possible split: n = num1 + num2
        for (int i = 1; i <= n; i++)
        {
            int num1 = i;
            int num2 = n - i;

            // If both numbers have no zero in their digits
            if (noZeroCheck(num1, num2))
            {
                ans.push_back(num1);
                ans.push_back(num2);
                return ans; // return the first valid pair found
            }
        }

        // Should not reach here, since a valid pair always exists
        return ans;
    }

    // Optimal solution
    vector<int> getNoZeroIntegers(int n)
    {
        // TC: O(log n)  -> process each digit of n
        // SC: O(1)      -> only uses a few variables

        int a = n;          // first number
        int b = 0;          // second number
        int placeValue = 1; // tracks the current digit place (1, 10, 100...)

        // Build numbers digit by digit
        while (n > 1)
        {
            int take = 1; // default digit we shift from 'a' to 'b'

            // If current digit of n is 1, shift 2 instead
            // (avoids creating a zero digit in either number)
            if (n % 10 == 1)
            {
                take = 2;
            }

            // Update 'a' and 'b' by moving 'take' at the current place
            a = a - take * placeValue;
            b = b + take * placeValue;

            // Reduce n and move to next higher digit
            n = (n - take) / 10;
            placeValue *= 10;
        }

        // Return the two numbers with no zero digits
        return {a, b};
    }
};
int main()
{
    Solution s;
    int n = 11;
    vector<int> ans = s.getNoZeroIntegers(n);
    cout << "Result: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers

Youtube: https://www.youtube.com/watch?v=ig4llTdg6_E

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Convert%20Integer%20to%20the%20Sum%20of%20Two%20No-Zero%20Integers.cpp

algorithm:

- Brute Force Approach:

- The task is to split n into two numbers whose digits contain no zero.
- Function noZeroCheck goes through each digit of a number and makes sure no digit is 0.
- In the main function, we try all possible pairs: (i, n - i).
- For each pair, check if both numbers pass the no-zero check.
- The first valid pair is stored and returned.
- The solution works because a valid pair is always guaranteed.

- Optimal Approach:

- Start with two numbers: a = n, b = 0.
- Process n digit by digit from right to left.
- At each digit:
- Normally move 1 to b.
- If the digit is 1, move 2 instead (so that neither number gets a 0).
- Keep track of the digit’s place (1, 10, 100, …) so updates go into the correct position.
- Continue until all digits are handled.
- Return the final pair (a, b) which always adds up to n and has no zeros.

*/

/*

1317. Convert Integer to the Sum of Two No-Zero Integers

No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions,
you can return any of them.

Example 1:

Input: n = 2
Output: [1,1]
Explanation: Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.

Example 2:

Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.

Constraints:

2 <= n <= 10^4

*/

/*
************* Java Code **************

    public int[] getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int placeValue = 1;

        while (n > 1) {
            int take = 1;

            if (n % 10 == 1) {
                take = 2;
            }
            a = a - take * placeValue;
            b = b + take * placeValue;

            n = (n - take) / 10;
            placeValue *= 10;
        }

        return new int[] { a, b };
    }

*/