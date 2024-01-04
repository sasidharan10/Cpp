#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto &&it : mp)
        {
            if (it.second == 1)
                return -1;
            else if (it.second % 3 == 0)
                cnt += it.second / 3;
            else
                cnt += (it.second / 3) + 1;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 3, 3, 2, 2, 4, 2, 3, 4};
    cout << "Minimum Operations to Make Array Empty: " << s.minOperations(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty

Youtube:

algorithm:

- We can only remove elements if its occurence is 2x or 3x. hence, if the elements 
  occurence is 1, we return -1.
- if its occurence is greater than 2, then we check if it is a multiple of 3.
- if yes, then we remove it, and count its operation.
- If no, then we try to eliminate the elements by grouping into 3, as much as we can. 
- Ex: 3,6,9,12 can be removed by 2nd operation in 1,2,3,4 oprations.
- Ex: 4,7,11 can be removed by [2,2] = 2, [2,2,3] = 3, and [3,3,3,2] = 4 operations.
- hence if the occurence is not divisible by 3, then it will take (x%3) + 1 operations
  to remove that element.

*/

/*

2870. Minimum Number of Operations to Make Array Empty

You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty,
or -1 if it is not possible.

Example 1:

Input: nums = [2,3,3,2,2,4,2,3,4]
Output: 4
Explanation: We can apply the following operations to make the array empty:
- Apply the first operation on the elements at indices 0 and 3.
The resulting array is nums = [3,3,2,4,2,3,4].
- Apply the first operation on the elements at indices 2 and 4.
The resulting array is nums = [3,3,4,3,4].
- Apply the second operation on the elements at indices 0, 1, and 3.
The resulting array is nums = [4,4].
- Apply the first operation on the elements at indices 0 and 1.
The resulting array is nums = [].
It can be shown that we cannot make the array empty in less than 4 operations.

Example 2:

Input: nums = [2,1,2,2,3,3]
Output: -1
Explanation: It is impossible to empty the array.

*/