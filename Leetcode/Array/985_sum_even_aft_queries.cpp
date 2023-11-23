#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = queries.size();
        int m = nums.size();
        int val, index, evenSum = 0, prev, newVal;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
                evenSum += nums[i];
        }

        for (int i = 0; i < m; i++)
        {
            val = queries[i][0];
            index = queries[i][1];
            prev = nums[index];
            newVal = nums[index] + val;
            if (nums[index] % 2 == 0)
            {
                if (newVal % 2 == 0)
                    evenSum = evenSum - prev + newVal;
                else
                    evenSum = evenSum - prev;
            }
            else
            {
                if (newVal % 2 == 0)
                    evenSum = evenSum + newVal;
            }
            nums[index] += val;
            ans.push_back(evenSum);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> queries = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
    vector<int> ans = s.sumEvenAfterQueries(nums, queries);
    cout << "Sum of Even Numbers After Queries: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/

Youtube:

algorithm:

*/

/*

985. Sum of Even Numbers After Queries

You are given an integer array nums and an array queries where queries[i] = [vali, indexi].
For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print the sum of
the even values of nums.
Return an integer array answer where answer[i] is the answer to the ith query.

Example 1:

Input: nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation: At the beginning, the array is [1,2,3,4].
After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.
Example 2:

Input: nums = [1], queries = [[4,0]]
Output: [0]


*/