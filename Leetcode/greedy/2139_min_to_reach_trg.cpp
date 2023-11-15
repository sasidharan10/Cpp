#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {
        int moves = 0;
        while (target != 1)
        {
            if (target % 2 != 0)
            {
                target--;
                moves++;
            }
            else if (maxDoubles > 0)
            {
                target /= 2;
                moves++;
                maxDoubles--;
            }
            else
            {
                moves += target - 1;
                break;
            }
        }
        return moves;
    }
};
int main()
{
    Solution s;
    int target = 19, maxDoubles = 2;
    cout << "Minimum Moves to Reach Target Score: " << s.minMoves(target, maxDoubles) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-moves-to-reach-target-score/

Youtube:

algorithm:

- Greedy approach
- we go from reverse, since we can divide the bigger numbers first, which eventually
  reduces the no of steps.
*/