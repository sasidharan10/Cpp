#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
class Solution
{
public:
    void findDuplicate2(vector<int> &nums)
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
        cout << "Duplicate: " << slow << endl;
    }
};
int main()
{
    Solution s;
    vector<int> v{7, 8, 6, 1, 5, 2, 4, 3, 1};
    // s.findDuplicate1(v);
    s.findDuplicate2(v);
    cout << endl;
    return 0;
}