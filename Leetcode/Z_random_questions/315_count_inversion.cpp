#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int count = 0;
    void merge(vector<pair<int, int>> &v, int left, int mid, int right, vector<int> &ans)
    {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right)
        {
            if (v[i].first >= v[j].first)
            {
                ans[v[i].second] = right - j + 1;
                temp[k++] = v[i++];
            }
            else
            {
                temp[k++] = v[j++];
            }
        }
        while (i <= mid)
        {
            temp[k++] = v[i++];
        }
        while (j <= right)
        {
            temp[k++] = v[j++];
        }
        for (int i = left; i <= right; i++)
        {
            v[i] = temp[i - left];
        }
    }
    void mergeSort(vector<pair<int, int>> &v, int left, int right, vector<int> &ans)
    {
        if (left >= right)
            return;
        int mid = left + ((right - left) / 2);
        mergeSort(v, left, mid, ans);
        mergeSort(v, mid + 1, right, ans);
        merge(v, left, mid, right, ans);
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = make_pair(nums[i], i);
        }
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i].first << " " << v[i].second << endl;
        }
        mergeSort(v, 0, n - 1, ans);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{5, 2, 6, 1};
    vector<int> ans = s.countSmaller(nums);
    cout << "Count: " << s.count << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/

*/