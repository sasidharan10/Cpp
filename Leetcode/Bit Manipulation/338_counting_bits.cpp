#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> countBits2(int n)
    {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            int res = 0;
            if (i % 2 != 0)
            {
                res = res + 1 + ans[i / 2];
            }
            else
            {
                res = ans[i / 2];
            }
            ans.push_back(res);
        }
        return ans;
    }

    // better
    vector<int> countBits(int n)
    {
        vector<int> ans;
        ans.push_back(0);
        int temp = 0;
        for (int i = 1; i <= n; i++)
        {
            int res = 0;
            temp = i;
            while (temp > 0)
            {
                res++;
                temp = temp & (temp - 1);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 5;
    vector<int> ans = s.countBits(n);
    cout << "No of 1s: ";
    for (int i : ans)
        cout << i << " ";
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/counting-bits/description/

Youtube: https://www.youtube.com/watch?v=awxaRgUB4Kw

algorithm:

- Refer LC 191, for learning all methods to count no of '1's bit
- We basically do n = n & (n - 1), which will eliminate one '1' bit in each
  operation, until the number becomes 0.
- Ex:
  step 1 => 1000001 & 1000000 = 100000
  step 2 => 1000000 & 0111111 = 000000
  which implies, it took 2 operations to remove all '1's, hence result is 2.

- In 2nd approach, we right shift the number each time, which means the numbers
  value gets reduced, and its answer would have been already stored in the array
- So if its an odd number, we add 1 + result of n>>1 i.e, ans[i/2];
- If its even, last bit is 0, so we directly add res = ans[i/2].
- Remember, i/2 == i>>1 and i%2 == i&1
*/

/*

338. Counting Bits

Given an integer n, return an array ans of length n + 1 such that
for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.


Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

*/