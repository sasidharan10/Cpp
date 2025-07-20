#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        // TC: O(log n)
        // SC: O(1)

        int ans = 0; // Initialize the reversed number to 0
        while (x != 0)
        {
            int digit = x % 10; // Get the last digit of x

            // Check for overflow/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
            {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }

            ans = ans * 10 + digit; // Append the digit to the reversed number
            x = x / 10;             // Remove the last digit from x
        }
        return ans; // Return the reversed number
    }
};
int main()
{
    Solution s;
    int n = -123;
    cout << "Result: " << s.reverse(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reverse-integer/

Youtube: https://www.youtube.com/watch?v=HAgLH58IgJQ

Code Link:

algorithm:

- Brute Force Approach:

- We can also convert the input to string, then reverse it, then convert it back to integer, and assign the sign, but
  we need to hold that value in Long datatype as we cannot convert the 
  last -ve integer value to positive integer(since the limit is -2,147,483,648 to 2,147,483,647).

- Optimal Approach:

- Just do a integer overflow check.

*/

/*

7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go
outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


Constraints:

-2^31 <= x <= 2^31 - 1


*/

/*
************* Java Code **************

    public int reverse(int x) {
        // TC: O(log n)
        // SC: O(1)

        int ans = 0; // Initialize the reversed number to 0
        while (x != 0) {
            int digit = x % 10; // Get the last digit of x

            // Check for overflow/underflow before updating ans
            if (ans > Integer.MAX_VALUE / 10 || ans < Integer.MIN_VALUE / 10) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }

            ans = ans * 10 + digit; // Append the digit to the reversed number
            x = x / 10; // Remove the last digit from x
        }
        return ans; // Return the reversed number
    }

*/