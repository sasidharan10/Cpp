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

*/