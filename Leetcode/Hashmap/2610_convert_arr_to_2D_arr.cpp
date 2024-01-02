#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        int n = nums.size();
        int mp[201];
        memset(mp, 0, sizeof(mp));
        // vector<int> mp(n + 1, 0);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int freq = mp[nums[i]];
            if (freq == ans.size())
            {
                ans.push_back({});
            }
            ans[freq].push_back(nums[i]);
            mp[nums[i]]++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 3, 4, 1, 2, 3, 1};
    vector<vector<int>> ans = s.findMatrix(nums);
    cout << "Resultant 2D Array: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions

Youtube: https://www.youtube.com/watch?v=BR--_W8odmw

algorithm:

- its given that , we need to create the 2D array such that, every row should
  have distinct elements and no of row should be minimum.
- Hence, the resultant 2D array will have rows = max occurence of an element.
- Since we need to make every row distinct, each occurence should be kept
  in separete row.
- Hence we take a map, traverse through each element, and check if(freq == ans.size()),
  means, we need to add a new row to "ans", since that elements occurence is increased.

*/

/*

2610. Convert an Array Into a 2D Array With Conditions

You are given an integer array nums. You need to create a 2D array from
nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

Example 1:

Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains
distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.

Example 2:

Input: nums = [1,2,3,4]
Output: [[4,3,2,1]]
Explanation: All elements of the array are distinct, so we can keep all
of them in the first row of the 2D array.

*/