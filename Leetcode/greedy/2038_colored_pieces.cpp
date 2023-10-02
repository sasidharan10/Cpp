#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int tota = 0, totb = 0;
        for (int i = 1; i < colors.length() - 1; i++)
        {
            char prev = colors[i - 1];
            char next = colors[i + 1];
            char cur = colors[i];
            if (prev == cur && cur == next)
            {
                if (cur == 'A')
                    tota++;
                else
                    totb++;
            }
        }
        return tota > totb;
    }
};
int main()
{
    Solution s;
    string str = "ABBBBBBBAAA";
    // string str = "AAAABBBB";
    cout << "Alice or Bob?: " << s.winnerOfGame(str);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

Youtube:

algorithm: just count no of "AAA" and "BBB" and return which is greater

*/