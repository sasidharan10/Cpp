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

*/