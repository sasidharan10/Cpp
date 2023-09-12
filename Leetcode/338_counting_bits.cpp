#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
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

*/