#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int temp = (a & b) << 1;
            a = a ^ b;
            b = temp;
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

*/