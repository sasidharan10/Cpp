#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hammingWeight1(uint32_t n)
    {
        // TC: O(32)
        // SC: O(1)

        int count = 0;
        while (n > 0)
        {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
    int hammingWeight2(uint32_t n)
    {
        // TC: O(32)
        // SC: O(1)

        int count = 0;
        while (n > 0)
        {
            count += n % 2;
            n = n / 2;
        }
        return count;
    }
    int hammingWeight3(uint32_t n)
    {
        // TC: O(1) faster
        // SC: O(1)

        int count = 0;
        while (n > 0)
        {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
    int hammingWeight(uint32_t n)
    {
        // return hammingWeight1(n);
        return hammingWeight2(n);
    }
};
int main()
{
    Solution s;
    uint32_t n = 00000000000000000000000000001011;
    cout << "No of 1s: " << s.hammingWeight(n) << endl;
    cout << "No of 1s: " << s.hammingWeight3(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-1-bits/

Youtube: https://www.youtube.com/watch?v=5Km3utixwZs

algorithm:

- We get the last bit, and check if its 1 or 0, and then update the count.
- We can do (n & 1) to get the value of last bit, then add to the result.
- then we can right shift the number by (n = n >> 1), to check the next bit,
  untill the numbber becomes 0.
- (n & 1) and (n % 2) works same, to find the last bit.
- (n = n >> 1) ans (n = n / 2) also works the same, to right shift the number.
- Third solution is not intuitive, but still good to know and its lot faster.

- we basically do n = n & (n - 1), which will eliminate one '1' bit in each
  operation, until the number becomes 0.
- Ex:
  step 1 => 1000001 & 1000000 = 100000
  step 2 => 1000000 & 0111111 = 000000
  which implies, it took 2 operations to remove all '1's, hence result is 2.

*/


/*

191. Number of 1 Bits

Write a function that takes the binary representation of an unsigned integer 
and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In 
this case, the input will be given as a signed integer type. It should not affect 
your implementation, as the integer's internal binary representation is the same, 
whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. 
Therefore, in Example 3, the input represents the signed integer. -3.
 

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

*/