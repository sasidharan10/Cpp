#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFlips2(int a, int b, int c)
    {
        // TC: O(32)
        // SC: O(32) * 3

        bitset<32> A(a);
        bitset<32> B(b);
        bitset<32> C(c);

        string x = A.to_string();
        string y = B.to_string();
        string z = C.to_string();

        int res = 0;
        for (int i = 31; i >= 0; i--)
        {
            int a = x[i] - '0';
            int b = y[i] - '0';
            int c = z[i] - '0';
            if ((a or b) != c)
            {
                if (c == 0 and a == 1 and b == 1)
                    res += 2;

                else
                    res += 1;
            }
        }
        return res;
    }
    int minFlips(int a, int b, int c)
    {
        // TC: O(32)
        // SC: O(1)

        int cnt = 0;
        // case 1:
        while (c > 0)
        {
            int bit3 = c % 2;
            c = c / 2;
            int bit1 = a % 2;
            a = a / 2;
            int bit2 = b % 2;
            b = b / 2;
            if (bit3 == 0)
            {
                if (bit1 == 1 && bit2 == 1)
                    cnt += 2;
                else if (bit1 == 1 || bit2 == 1)
                    cnt += 1;
            }
            else
            {
                if (bit1 == 0 && bit2 == 0)
                    cnt += 1;
            }
        }
        // case 2:
        while (a > 0 && b > 0)
        {
            int bit1 = a % 2;
            a = a / 2;
            int bit2 = b % 2;
            b = b / 2;
            if (bit1 == 1 && bit2 == 1)
                cnt += 2;
            else if (bit1 == 1 || bit2 == 1)
                cnt += 1;
        }
        // case 3:
        while (a > 0)
        {
            int bit1 = a % 2;
            a = a / 2;
            if (bit1 == 1)
                cnt += 1;
        }
        while (b > 0)
        {
            int bit2 = b % 2;
            b = b / 2;
            if (bit2 == 1)
                cnt += 1;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    int a = 2, b = 6, c = 5;
    cout << "Result: " << s.minFlips(a, b, c) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

Youtube:

algorithm:

- case 1: we run the loop, until we exhaust number "c".
  we take the right most bit from a, b, c, and check if we want to change the
  a ,b bits, if yes, then we increase the count, and then check for next right
  most bit.
- case 2: So number "c" is 0, but a and b can have some more bits in its left,
  hence we run the loop again, to make them 0.
- case 3: Now a and b might still have some 1 bits in its left, which needs to be
  converted to 0, hence we run the loop to make them 0.

- In 2nd pproach, we basically do the same, but here we store 32 bits of a,b,c in
  string, and check them all at once.
- If we need to change the bits, we increase the count as per the requirement.

*/

/*

1318. Minimum Flips to Make a OR b Equal to c

Given 3 positives numbers a, b and c. Return the minimum flips required
in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the
bit 0 to 1 in their binary representation.

Example 1:

Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

Example 2:

Input: a = 4, b = 2, c = 7
Output: 1

Example 3:

Input: a = 1, b = 2, c = 3
Output: 0

*/