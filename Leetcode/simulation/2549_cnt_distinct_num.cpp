#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    int distinctIntegers2(int n)
    {
        queue<int> q;
        unordered_set<int> s;
        q.push(n);
        s.insert(n);
        int cnt = 1, x;
        while (!q.empty())
        {
            x = q.front();
            q.pop();
            for (int i = 1; i <= n; i++)
            {
                if (x % i == 1)
                {
                    if (s.count(i) == 0)
                    {
                        cnt++;
                        q.push(i);
                        s.insert(i);
                    }
                }
            }
        }
        return cnt;
    }
    // Optimal
    int distinctIntegers(int n)
    {
        if (n == 1)
            return n;
        return n - 1;
    }
};
int main()
{
    Solution s;
    int n = 7;
    cout << "Count Distinct Numbers on Board: " << s.distinctIntegers(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-distinct-numbers-on-board

Youtube:

algorithm:

*/

/*

2549. Count Distinct Numbers on Board

You are given a positive integer n, that is initially placed on a board.
Every day, for 109 days, you perform the following procedure:

For each number x present on the board, find all numbers 1 <= i <= n such that x % i == 1.
Then, place those numbers on the board.
Return the number of distinct integers present on the board after 109 days have elapsed.

Note:

Once a number is placed on the board, it will remain on it until the end.
% stands for the modulo operation. For example, 14 % 3 is 2.


Example 1:

Input: n = 5
Output: 4
Explanation: Initially, 5 is present on the board.
The next day, 2 and 4 will be added since 5 % 2 == 1 and 5 % 4 == 1.
After that day, 3 will be added to the board because 4 % 3 == 1.
At the end of a billion days, the distinct numbers on the board will be 2, 3, 4, and 5.
Example 2:

Input: n = 3
Output: 2
Explanation:
Since 3 % 2 == 1, 2 will be added to the board.
After a billion days, the only two distinct numbers on the board are 2 and 3.


*/