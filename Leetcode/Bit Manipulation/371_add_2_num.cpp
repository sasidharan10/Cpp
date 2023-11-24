#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
int main()
{
    Solution s;
    int a = 2, b = 3;
    cout << "Sum of A and B: " << s.getSum(a, b) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sum-of-two-integers/

Youtube: https://www.youtube.com/watch?v=gVUrDV4tZfY&t=499s

algorithm:

- To find carry, we do carry = (a & b) << 1;
- To find current sum of bits, we do a = a ^ b
- then assign b = carry, and we run the loop, until b becomes 0.
*/

/*

371. Sum of Two Integers

Given two integers a and b, return the sum of the two integers 
without using the operators + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5


*/