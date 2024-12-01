#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> v, int target)
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

vector<int> twoSum2(vector<int> v, int target)
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


bool twoSum3(vector<int> v, int target)
{
    // TC: O(n) + O(nlogn)
    // SC: O(1)

    // using 2-pointer approach
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


/*

1. Two Sum

Given an array of integers nums and an integer target, return indices of the two 
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not 
use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/