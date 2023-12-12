#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int guess(int num);
    int guessNumber(int n)
    {
        int low = 1, x;
        unsigned long long int high = n;
        while (low <= high)
        {
            unsigned long long int mid = (low + high) / 2;
            if (guess(mid) == 0)
            {
                x = mid;
                break;
            }
            else if (guess(mid) == 1)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return x;
    }
};
int main()
{
    Solution s;
    int n = 10;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/guess-number-higher-or-lower

Youtube:

algorithm:

- Implement binary search

*/

/*

374. Guess Number Higher or Lower

We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I will tell you whether the number I picked
is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.

Example 1:

Input: n = 10, pick = 6
Output: 6
Example 2:

Input: n = 1, pick = 1
Output: 1
Example 3:

Input: n = 2, pick = 1
Output: 1

*/