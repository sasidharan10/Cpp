#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else if (nums1[i] == nums2[j])
            {
                ans.insert(nums1[i]);
                i++;
                j++;
            }
        }
        vector<int> v(ans.begin(), ans.end());
        return v;
    }
};
int main()
{
    Solution s;
    vector<int> a{4, 9, 5};
    vector<int> b{9, 4, 9, 8, 4};
    vector<int> ans = s.intersection(a, b);
    cout << "Intersection: ";
    for (int i : ans)
        cout << i << " ";
}