#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverseNum(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            int r = num % 10;
            sum = (sum * 10) + r;
            num = num / 10;
        }
        return sum;
    }
    int countNicePairs(vector<int> &nums)
    {
        // TC: O(nlogN)
        // SC: O(n)
        
        long long count = 0;
        int mod = 1e9 + 7;
        int n = nums.size();
        unordered_map<long, long> map;
        for (int i = 0; i < n; i++)
        {
            long temp = nums[i] - reverseNum(nums[i]);
            map[temp]++;
        }
        for (auto &&i : map)
        {
            int temp = i.second;
            if (temp > 1)
            {
                long long sum = (temp * (temp - 1)) / 2;
                count += sum;
                count = count % mod;
            }
        }
        return count % mod;
    }
};
int main()
{
    Solution s;
    vector<int> nums{42, 11, 1, 97};
    cout << "No of nice Pairs: " << s.countNicePairs(nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-nice-pairs-in-an-array/description/

Youtube: https://www.youtube.com/watch?v=HgYxzKsToBo

algorithm:

- Formula given:
  => nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
  => nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
- Hence, we Find the sum of pairs, 1 num reversed, and store the result in a map.
- Then using the count of the pair sum, we can find the total no of combinations.
- use nCr formula
- here we know we have to find the combinations of 2, hence simplifying nCr formula,
  we get n(n*1)/2, which is same as sum 1....n.

*/


/*

1814. Count Nice Pairs in an Array

You are given an array nums that consists of non-negative integers. Let us define rev(x) as the 
reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair 
of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number 
can be too large, return it modulo 109 + 7.


Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
Example 2:

Input: nums = [13,10,35,24,76]
Output: 4

*/