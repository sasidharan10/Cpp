#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + l);
        reverse(nums.begin() + l, nums.end());
    }
};
int main()
{
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    s.rotate(v, k);
    cout << "\nArray right rotation : ";
    for (auto i : v)
        cout << i << " ";
    return 0;
}