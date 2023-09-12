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
            count += n % 2;
            n = n / 2;
        }
        return count;
    }
    int hammingWeight2(uint32_t n)
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
    cout << "No of 1s: " << s.hammingWeight(n);
    return 0;
}