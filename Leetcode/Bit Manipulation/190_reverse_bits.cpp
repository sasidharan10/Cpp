#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t res = 0;
    for (int i = 31; i >= 0; i--)
    {
      int temp = n & 1;
      n = n >> 1;
      temp = temp << i;
      res = res | temp;
    }
    return res;
  }
};
int main()
{
  Solution s;
  uint32_t n = 4294967293;
  cout << "Reverse bit: " << s.reverseBits(n);
  return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reverse-bits/description/

Youtube: https://www.youtube.com/watch?v=UcoN6UjAI64

algorithm:

- its given that the no is s 32 bit integer, hence we need to reverse those 32 bits.
- we take the right most bit(1st) first, then place it to the result in reverse order(31st)
  position.
- We do this by, doing (temp = n & 1), to get that last bit, then left shift it 31 times.
- Add that temp to the result, by doing (res | temp). then we take next  bit, shift it by
  30 bits, and so on.

*/

/*

190. Reverse Bits

Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case,
both input and output will be given as a signed integer type. They should not affect your
implementation, as the integer's internal binary representation is the same, whether it is
signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore,
in Example 2 above, the input represents the signed integer -3 and the output represents
the signed integer -1073741825.


Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents
the unsigned integer 43261596, so return 964176192 which its binary representation
is 00111001011110000010100101000000.
Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents
the unsigned integer 4294967293, so return 3221225471 which its binary representation
is 10111111111111111111111111111111.

*/