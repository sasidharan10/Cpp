#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int Partition(vector<int> &nums, int start, int end)
    {
        int p_index = start;
        int pivot = nums[end];
        for (int i = start; i < end; i++)
        {
            if (nums[i] <= pivot)
            {
                swap(nums[i], nums[p_index]);
                p_index++;
            }
        }
        swap(nums[end], nums[p_index]);
        return p_index;
    }
    int quickSelect(vector<int> &nums, int start, int end, int k)
    {

        if (start > end)
            return -1;
        int p_index = Partition(nums, start, end);
        if (p_index == k - 1)
            return nums[p_index];
        else if (p_index > k - 1)
            return quickSelect(nums, start, p_index - 1, k);
        else
            return quickSelect(nums, p_index + 1, end, k);
        // return -1;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k + 1);
    }
};
int main()
{
    Solution s;
    vector<int> a{3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "Kth largest: " << s.findKthLargest(a, k);
    // for (int i : a)
    //     cout << i << " ";
    return 0;
}

/*

leetcode: https://leetcode.com/problems/kth-largest-element-in-an-array/

*/