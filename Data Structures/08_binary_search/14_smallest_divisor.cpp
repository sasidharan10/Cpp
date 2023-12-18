#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int calcSumDivisor(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)nums[i] / (double)x);
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int sum = calcSumDivisor(nums, mid);
            if (sum <= threshold)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{1, 2, 5, 9};
    // int threshold = 6;
    vector<int> nums{44, 22, 33, 11, 1};
    int threshold = 5;
    cout << "Result: " << s.smallestDivisor(nums, threshold) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/smallest-divisor-with-the-given-limit_1755882

leetcode: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

Youtube: https://www.youtube.com/watch?v=UvBKTVaG6U8&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=15

algorithm:

- the smallest value possible will be 1, and max value will be the max element 
  from the array(since ceil(nums[i]/max) == 1, it cannot be greater than that).
- now we use binary search, and check if mid element satisfies the condition,
  if yes, then we assign it as answer, and check if even smaller element exists.
   
*/

/*

1283. Find the Smallest Divisor Given a Threshold

Given an array of integers nums and an integer threshold, we will choose a
positive integer divisor, divide all the array by it, and sum the division's
result. Find the smallest divisor such that the result
mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer
greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the
divisor is 5 the sum will be 5 (1+1+1+2).

Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44




*/