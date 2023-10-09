#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> v, int target)
{
    // TC: O(nlogn)
    // SC: O(n)

    unordered_map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        if (m.find(target - v[i]) != m.end())
        {
            ans.push_back(m[target - v[i]]);
            ans.push_back(i);
            return ans;
        }
        else
            m[v[i]] = i;
    }
    return ans;
}

vector<int> twoSum2(vector<int> v, int target)
{
    // TC: O(n^2) brute force
    // SC: O(1)

    vector<int> ans;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] + v[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

bool twoSum3(vector<int> v, int target)
{
    // TC: O(n) + O(nlogn)
    // SC: O(1)

    // to check if 2 sum pair exists,
    sort(v.begin(), v.end());
    int left = 0, right = v.size() - 1;
    while (left < right)
    {
        if (v[left] + v[right] == target)
        {
            return true;
        }
        else if (v[left] + v[right] > target)
        {
            right--;
        }
        else
            left++;
    }
    return false;
}
int main()
{
    vector<int> v{8, 2, 14, 4, 5, 6};
    int target = 20;
    v = twoSum(v, target);
    for (auto i : v)
        cout << i << " ";
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/two-sum/

Youtube: https://www.youtube.com/watch?v=UXDSeD9mN-k

algorithm:

*/