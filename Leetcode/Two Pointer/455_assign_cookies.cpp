#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, cnt = 0;
        while (i < n && j < m)
        {
            if (g[i] <= s[j])
            {
                cnt++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> g = {1, 2}, nums = {1, 2, 3};
    cout << "Result: " << s.findContentChildren(g, nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/assign-cookies

Youtube:

algorithm:

*/

/*






*/