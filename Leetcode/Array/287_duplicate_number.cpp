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
        // TC: O(n)
        // SC: O(1)

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

Youtube: https://www.youtube.com/watch?v=wjYnzkAhcNk

algorithm:

- Floyd cycle detection
- We find the index, where the cycle occurs.
- then initialize slow = 0, then move slow, fast by 1 index, until they meet.
- The intersection value is the duplicate element.
*/