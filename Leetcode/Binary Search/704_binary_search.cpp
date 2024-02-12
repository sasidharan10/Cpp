#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int beg = 0;
        int mid = 0;
        int end = nums.size() - 1;
        while (beg <= end)
        {
            mid = beg + (end - beg) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return INT_MIN;
    }
};
int main()
{
    Solution s;
    vector<int> a{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ans = 0;
    int x = 5;
    ans = s.search(a, x);
    if (ans != INT_MIN)
        cout << "Found at index : " << ans << endl;
    else
        cout << "Not found!!!";
}

/*

leetcode: https://leetcode.com/problems/binary-search/

*/