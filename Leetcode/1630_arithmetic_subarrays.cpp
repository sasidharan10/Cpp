#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal without sorting, but brute is working better than this
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int n = l.size();
        vector<bool> ans;
        bool curAns;
        int st, en, m, diff, mini, maxi, cur;
        for (int i = 0; i < n; i++)
        {
            st = l[i];
            en = r[i];
            vector<int> v(nums.begin() + st, nums.begin() + en + 1);
            mini = *min_element(v.begin(), v.end());
            maxi = *max_element(v.begin(), v.end());
            unordered_set<int> st(v.begin(), v.end());
            curAns = true;
            m = v.size();
            if ((maxi - mini) % (m - 1) != 0)
            {
                ans.push_back(false);
                continue;
            }
            // arithmetic progression formula
            diff = (maxi - mini) / (m - 1);
            cur = mini + diff;
            while (cur < maxi)
            {
                if (st.find(cur) == st.end())
                {
                    curAns = false;
                    break;
                }
                cur += diff;
            }
            ans.push_back(curAns);
        }
        return ans;
    }
    // brute
    vector<bool> checkArithmeticSubarrays2(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        // TC: O(n*mlogm)
        // SC: O(n*m)

        int n = l.size();
        vector<bool> ans;
        bool curAns;
        int st, en, m, diff;

        for (int i = 0; i < n; i++)
        {
            st = l[i];
            en = r[i];
            vector<int> v(nums.begin() + st, nums.begin() + en + 1);
            sort(v.begin(), v.end());
            curAns = true;
            m = v.size();
            if (m <= 1)
            {
                ans.push_back(true);
                continue;
            }
            diff = v[1] - v[0];
            for (int k = 1; k < m - 1; k++)
            {
                if (v[k + 1] - v[k] != diff)
                {
                    curAns = false;
                    break;
                }
            }
            ans.push_back(curAns);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{4, 6, 5, 9, 3, 7};
    vector<int> l{0, 0, 2}, r{2, 3, 5};
    vector<bool> ans = s.checkArithmeticSubarrays(nums, l, r);
    cout << "Is the Subarray can be rearranged to form an Arithmetic Sequence: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/arithmetic-subarrays

Youtube:

algorithm:

- Arithmetc progression formula = A(n) = A + (n-1)D;
- => (A(n) - A)/(n-1) = D

*/