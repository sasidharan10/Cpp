#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void removeSenator(char ch, int ind, int n, string &senate, vector<bool> &removed)
    {

        while (true)
        {
            if (!removed[ind] && senate[ind] == ch)
            {
                removed[ind] = true;
                break;
            }
            ind = (ind + 1) % n;
        }
    }
    string predictPartyVictory2(string senate)
    {
        // TC: O(n)
        // SC: O(n)

        int n = senate.length();
        int d_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'D')
                d_count++;
        }
        vector<bool> removed(n, false);
        int r_count = n - d_count;
        int ind = 0;
        while (d_count > 0 && r_count > 0)
        {
            if (!removed[ind])
            {
                if (senate[ind] == 'D')
                {
                    removeSenator('R', (ind + 1) % n, n, senate, removed);
                    r_count--;
                }
                else
                {
                    removeSenator('D', (ind + 1) % n, n, senate, removed);
                    d_count--;
                }
            }
            ind = (ind + 1) % n;
        }
        return d_count > 0 ? "Dire" : "Radiant";
    }

    string predictPartyVictory(string senate)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = senate.length();
        queue<int> dire, radiant;
        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'D')
                dire.push(i);
            else
                radiant.push(i);
        }
        while (!dire.empty() && !radiant.empty())
        {
            int dr = dire.front();
            dire.pop();
            int rad = radiant.front();
            radiant.pop();
            if (dr < rad)
                dire.push(dr + n);
            else
                radiant.push(rad + n);
        }
        if (dire.empty())
            return "Radiant";
        else
            return "Dire";
    }
};
int main()
{
    Solution s;
    string senate = "RDD";
    cout << "The Party won: " << s.predictPartyVictory(senate) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/dota2-senate

Youtube: https://www.youtube.com/watch?v=r3lOL6srx1E

algorithm:

- String contains R and D values. Its given both parties only make the best
  possible option in their turn. The best option is to remove voting rights
  of immediate next opponent.
- First we take count of both parties.
- Then we traverse from left to right, at each round, we find its immediate next
  opponent, and mark to remove their rights. we do this until one party's count
  becomes 0. and the remaining party wins.
- if array gets exhausted, we traverse again from first, until 1 party gets exhausted.

- Once a party chooses 1 option, we move to next party and again do the same
  operation for that party. So we dont make any changes to the current
  party, and it can appear again also, in next traversal, after the array
  gets exhausted.
*/

/*

649. Dota2 Senate

In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate
wants to decide on a change in the Dota2 game. The voting for this change is
a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his
rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have
rights to vote are all from the same party, he can announce the victory
and decide on the change in the game.
Given a string senate representing each senator's party belonging.
The character 'R' and 'D' represent the Radiant party and the Dire party.
Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last
senator in the given order. This procedure will last until the end of voting.
All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy
for his own party. Predict which party will finally announce the
victory and change the Dota2 game. The output should be "Radiant" or "Dire".

Example 1:

Input: senate = "RD"
Output: "Radiant"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And in round 2, the first senator can just announce the victory since
he is the only guy in the senate who can vote.

Example 2:

Input: senate = "RDD"
Output: "Dire"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And the third senator comes from Dire and he can ban the first senator's right in round 1.
And in round 2, the third senator can just announce the victory since
he is the only guy in the senate who can vote.

*/