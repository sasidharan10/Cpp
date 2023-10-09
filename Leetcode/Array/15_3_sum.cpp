#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    vector<vector<int>> threeSum2(vector<int> &nums)
    {
        // TC: O(n^3 + O(log(unique elements))
        // SC: O(n)

        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // better
    vector<vector<int>> threeSum3(vector<int> &nums)
    {
        // TC: O(n^2 * O(logm)
        // SC: O(n) + 2 * O(triplets)

        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            set<int> hashSet;
            for (int j = i + 1; j < n; j++)
            {
                int third = -(nums[i] + nums[j]);
                if (hashSet.find(third) != hashSet.end())
                {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // optimal
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    vector<int> temp{nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v{-1, 0, 1, 2, -1, -4};
    int target = 20;
    cout << "Three Sum: " << endl;
    vector<vector<int>> ans = s.threeSum(v);
    for (auto i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/3sum/description/

Youtube: https://www.youtube.com/watch?v=DhFh8Kw7ymk

algorithm:

*/