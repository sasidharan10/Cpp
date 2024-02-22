#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - graph
    int findJudge2(int n, vector<vector<int>> &trust)
    {
        int m = trust.size();
        vector<int> outDegree(n + 1, 0);
        vector<int> inDegree(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            int a = trust[i][0];
            int b = trust[i][1];
            outDegree[a]++;
            inDegree[b]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (inDegree[i] == n - 1 && outDegree[i] == 0)
                return i;
        }
        return -1;
    }

    // Optimal
    int findJudge(int n, vector<vector<int>> &trust)
    {
        int m = trust.size();
        vector<int> count(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            int a = trust[i][0];
            int b = trust[i][1];
            count[a]--;
            count[b]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (count[i] == n - 1)
                return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums = {{1, 3}, {2, 3}};
    int n = 3;
    cout << "Town Judge: " << s.findJudge(n, nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-town-judge/

Youtube: https://www.youtube.com/watch?v=ottPfSr3xls

algorithm:

- Brute Force Approach:

- Find the node with (outDegree == 0) i.e, the person, who trusts
  nobody and with (inDegree == n - 1) i.e, the person, who is trusted by
  every other person in the town.

- Optimal Approach:

- We can just use 1 array, to keep track of people who trust each other.
- A person who trusts somone will never be town judge, hence we mark it as -1.
- The guy, who got the trust, we increase his count.
- We return the person, having count == n - 1;

*/

/*

997. Find the Town Judge

In a town, there are n people labeled from 1 to n. There is a rumor that
one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that
the person labeled ai trusts the person labeled bi. If a trust relationship
does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can
be identified, or return -1 otherwise.

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

*/