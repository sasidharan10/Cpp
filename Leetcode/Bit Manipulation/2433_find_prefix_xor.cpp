#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int n = pref.size();
        for (int i = n - 1; i > 0; i--)
        {
            pref[i] = pref[i] ^ pref[i - 1];
        }
        return pref;
    }
};
int main()
{
    Solution s;
    vector<int> nums{5, 2, 0, 3, 1};
    vector<int> ans = s.findArray(nums);
    cout << "Original Array of Prefix Xor: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-original-array-of-prefix-xor

Youtube: https://www.youtube.com/watch?v=TDjmp768H3Q

algorithm:

*/