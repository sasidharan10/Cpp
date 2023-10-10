#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    int minOperations2(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(n)

        int n = nums.size();
        int maxi = INT_MIN;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int newSize = nums.size();
        for (int i = 0; i < newSize; i++)
        {
            int start = nums[i];
            int cnt = 0;
            for (int j = 0; j < newSize; j++)
            {
                if (nums[j] <= nums[i] + (n - 1) && nums[j] >= nums[i])
                    cnt++;
            }
            maxi = max(maxi, cnt);
        }
        return n - maxi;
    }
    // optimal
    int minOperations(vector<int> &nums)
    {
        // TC: O(nLogn)
        // SC: O(n)

        int n = nums.size();
        int res = n;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int newSize = nums.size();
        int end = 0;
        for (int start = 0; start < newSize; start++)
        {
            while (end < newSize && nums[end] < nums[start] + n)
            {
                end++;
            }
            int window = end - start;
            res = min(res, n - window);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{8, 5, 9, 9, 8, 4};
    cout << "Minimum operations to make the array continuous: " << s.minOperations(nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/

Youtube: https://www.youtube.com/watch?v=Dd-yJylrcOY

algorithm:

*/