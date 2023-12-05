#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute
    int numberOfMatches2(int n)
    {
        int cnt = 0;
        while (n != 1)
        {
            cnt += (n / 2);
            if (n % 2 != 0)
                n = (n / 2) + 1;
            else
                n = n / 2;
        }
        return cnt;
    }
    // Optimal
    int numberOfMatches(int n)
    {
        return n - 1;
    }
};
int main()
{
    Solution s;
    int n = 7;
    cout << "Count of Matches in Tournament: " << s.numberOfMatches(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-of-matches-in-tournament

Youtube:

algorithm:
- n = 127.
- It takes one match to eliminate one player. 126 players have to be eliminated
  to leave one winner. Therefore, there have to be 126 matches.

*/

/*

1688. Count of Matches in Tournament

You are given an integer n, the number of teams in a tournament that has strange rules:

If the current number of teams is even, each team gets paired with another team.
A total of n / 2 matches are played, and n / 2 teams advance to the next round.
If the current number of teams is odd, one team randomly advances in the tournament,
and the rest gets paired. A total of (n - 1) / 2 matches are played,
and (n - 1) / 2 + 1 teams advance to the next round.
Return the number of matches played in the tournament until a winner is decided.


Example 1:

Input: n = 7
Output: 6
Explanation: Details of the tournament:
- 1st Round: Teams = 7, Matches = 3, and 4 teams advance.
- 2nd Round: Teams = 4, Matches = 2, and 2 teams advance.
- 3rd Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
Total number of matches = 3 + 2 + 1 = 6.
Example 2:

Input: n = 14
Output: 13
Explanation: Details of the tournament:
- 1st Round: Teams = 14, Matches = 7, and 7 teams advance.
- 2nd Round: Teams = 7, Matches = 3, and 4 teams advance.
- 3rd Round: Teams = 4, Matches = 2, and 2 teams advance.
- 4th Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
Total number of matches = 7 + 3 + 2 + 1 = 13.


*/