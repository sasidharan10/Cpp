#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                bool flag = false;
                for (int l = i; l <= j; l++)
                {
                    flag = true;
                    sum += nums[l];
                }
                if (sum == k && flag)
                {
                    cnt++;
                    flag = false;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3};
    int k = 3;
    cout << "Total SubArray Sum K: " << s.subarraySum(nums, k) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/