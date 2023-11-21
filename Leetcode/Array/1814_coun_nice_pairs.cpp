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
        // TC: O(n)
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

Youtube:

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