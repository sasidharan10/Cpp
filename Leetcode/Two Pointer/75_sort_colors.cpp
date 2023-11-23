#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid++], nums[low++]);
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high--]);
            }
            else
                mid++;
        }
    }
};
int main()
{
    Solution s;
    vector<int> a{2, 0, 2, 1, 1, 0};
    s.sortColors(a);
    for (int i : a)
        cout << i << " ";
}

/*

leetcode: https://leetcode.com/problems/sort-colors/description/

*/
