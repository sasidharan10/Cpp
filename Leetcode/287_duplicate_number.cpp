#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 3, 4, 2, 2};
    cout << "Duplicate: " << s.findDuplicate(nums) << endl;
    return 0;
}


/*

link: 

leetcode: https://leetcode.com/problems/find-the-duplicate-number/description/

*/