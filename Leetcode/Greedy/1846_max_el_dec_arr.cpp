#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        if (arr[0] != 1)
            arr[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] <= 1)
                continue;
            arr[i] = arr[i - 1] + 1;
        }
        return arr[n - 1];
    }
};
int main()
{
    Solution s;
    vector<int> nums{100, 1, 1000};
    cout << "Maximum Element After Decreasing and Rearranging: " << s.maximumElementAfterDecrementingAndRearranging(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

Youtube:

algorithm:

*/