#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int sum = 0, fullSum = 0;
        // formula = n*(n+1)*0.5;
        for (int i = 0; i < nums.size(); i++)
        {
            fullSum += i;
            sum += nums[i];
        }
        fullSum += nums.size();
        return fullSum - sum;
    }
    int missingNumber(vector<int> &nums)
    {
        // TC: O(n) much faster
        // SC: O(1)

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ nums[i] ^ i;
        }
        ans = ans ^ nums.size();
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v{3, 0, 1};
    cout << "Missing Number: " << s.missingNumber(v);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/missing-number/description/

Youtube: https://www.youtube.com/watch?v=iCrQG_kbuP0

algorithm:

- we can get sum of n numbers using formula = n*(n-1)/2,
  or get the sum of all numbers, then subtract with the sum of array, to get the
  missing number.
- XOR = if 2 bits are same, XOR = 0
-       if 2 bits are different, XOR = 1
- A ^ B = B ^ A (commutative)
- A ^ (B ^ C)= (A ^ B) ^ C (associative)
- A ^ 0 = A
- A ^ A = 0 (both are same)
- Using XOR => consider arr{3, 0, 1}, n = 3

  We XOR the numbers in array, with its index, which means with every number
  in that array, and the matching numbers will be cancels out (A ^ A = 0).
  and the missing number will be left, since that was not present in the array
  but it was in the index.
  => (3 ^ 0 ^ 1) ^ (0 ^ 1 ^ 2 ^ 3)
  => 2

*/

/*

268. Missing Number

Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range 
[0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range 
[0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range 
[0,9]. 8 is the missing number in the range since it does not appear in nums.

*/