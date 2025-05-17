#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    // brute force
    int maxSubArray2(vector<int> &nums)
    {
        int n = size(nums), ans = INT_MIN;
        for (int i = 0; i < n; i++)
            for (int j = i, curSum = 0; j < n; j++)
                curSum += nums[j],
                    ans = max(ans, curSum);
        return ans;
    }

    long long maxSubarraySum(int arr[], int n) {
        long long maxi = LONG_MIN; // maximum sum
        long long sum = 0;
    
        for (int i = 0; i < n; i++) {
    
            sum += arr[i];
    
            if (sum > maxi) {
                maxi = sum;
            }
    
            // If sum < 0: discard the sum calculated
            if (sum < 0) {
                sum = 0;
            }
        }
    
        // To consider the sum of the empty subarray
        // uncomment the following check:
    
        //if (maxi < 0) maxi = 0;
    
        return maxi;
    }

    long long maxSubarraySum2(int arr[], int n) {
        long long maxi = LONG_MIN; // maximum sum
        long long sum = 0;
    
        int start = 0;
        int ansStart = -1, ansEnd = -1;
        for (int i = 0; i < n; i++) {
    
            if (sum == 0) start = i; // starting index
    
            sum += arr[i];
    
            if (sum > maxi) {
                maxi = sum;
    
                ansStart = start;
                ansEnd = i;
            }
    
            // If sum < 0: discard the sum calculated
            if (sum < 0) {
                sum = 0;
            }
        }
    
        //printing the subarray:
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << arr[i] << " ";
        }
        cout << "]n";
    
        // To consider the sum of the empty subarray
        // uncomment the following check:
    
        //if (maxi < 0) maxi = 0;
    
        return maxi;
    }

    int maxSubArray(vector<int> &nums)
    {
        int max_end_here = 0;
        int max_so_far = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            max_end_here = nums[i] + max_end_here;
            if (max_end_here > max_so_far)
            {
                max_so_far = max_end_here;
            }
            if (max_end_here < 0)
                max_end_here = 0;
        }
        return max_so_far;
    }
};
int main()
{
    Solution s;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray: " << s.maxSubArray(nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-subarray/description/

Youtube: https://www.youtube.com/watch?v=AHZpyENo7k4&t=870s

algorithm:

*/