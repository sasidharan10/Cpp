#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // TC: O(2n)
        // SC: O(1)

        int el1 = INT_MIN, cnt1 = 0, el2 = INT_MIN, cnt2 = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el1)
            {
                cnt1++;
            }
            else if (nums[i] == el2)
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0)
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (el1 == nums[i])
                cnt1++;
            if (el2 == nums[i])
                cnt2++;
        }
        if (cnt1 > (n / 3))
            ans.push_back(el1);
        if (cnt2 > (n / 3))
            ans.push_back(el2);
        return ans;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    vector<int> nums{1, 2};
    vector<int> ans = s.majorityElement(nums);
    cout << "Majority element : " << endl;
    for (auto &&i : ans)
        cout << i << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/majority-element-ii/description/

Youtube: https://www.youtube.com/watch?v=vwZj1K0e9U8

algorithm: Moore's Voting algorithm

- Brute force: run 2 loops, find count of every element and return the result. - O(n^2)
- Using Hashmap: store frequency and then check for each element if > (n/3).

- If find (n / 2) -> 1 majority element
- If find (n / 3) -> 2 majority element
- If find (n / 4) -> 3 majority element ...

*/