#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int t = 1;
        vector<string> ans;
        for (int i = 0; i < target.size(); i++)
        {
            while (t < target[i])
            {
                t++;
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
            t++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 3, 4};
    int n = 4;
    vector<string> ans = s.buildArray(nums, n);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/build-an-array-with-stack-operations

Youtube:

algorithm:

*/