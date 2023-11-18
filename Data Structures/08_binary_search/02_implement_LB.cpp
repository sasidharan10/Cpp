#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lowerBound(vector<int> arr, int n, int x)
    {
        // TC: O(logN)
        // SC: O(1)
        
        int low = 0;
        int high = n - 1;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 5, 8, 10};
    int n = nums.size();
    int x = 7;
    int index = s.lowerBound(nums, n, x);
    cout << "Lower Bound: " << nums[index] << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/lower-bound_8165382

leetcode: 

Youtube: 

algorithm: 

*/