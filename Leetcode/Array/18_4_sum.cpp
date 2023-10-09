#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    vector<vector<int>> fourSum2(vector<int> &nums, int target)
    {
        // TC: O(n^4 + O(log(unique elements))
        // SC: O(n)

        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == 0)
                        {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // better
    vector<vector<int>> fourSum3(vector<int> &nums, int target)
    {
        // TC: O(n^3 * O(logm)
        // SC: O(n) + 2 * O(quad)

        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            set<int> hashSet;
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int fourth = -(nums[i] + nums[j] + nums[k]);
                    if (hashSet.find(fourth) != hashSet.end())
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // optimal
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 1; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum > target)
                    {
                        l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        vector<int> temp{nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                        {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l + 1])
                        {
                            l--;
                        }
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
    vector<int> v{1, 0, -1, 0, -2, 2};
    int target = 0;
    // vector<int> v{2, 2, 2, 2, 2};
    // int target = 8;
    cout << "Four Sum: " << endl;
    vector<vector<int>> ans = s.fourSum(v, target);
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

leetcode: https://leetcode.com/problems/4sum/

Youtube: https://www.youtube.com/watch?v=eD95WRfh81c

algorithm:

*/