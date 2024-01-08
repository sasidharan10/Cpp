#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void calCombination(int index, vector<int> candidates, vector<int> temp, vector<vector<int>> &ans, int target)
    {
        if (index == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if (candidates[index] <= target)
        {
            temp.push_back(candidates[index]);
            calCombination(index, candidates, temp, ans, target - candidates[index]);
            temp.pop_back();
        }
        calCombination(index + 1, candidates, temp, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        calCombination(index, candidates, temp, ans, target);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = s.combinationSum(candidates, target);
    cout << "All Combinations with target sum: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/combination-sum/

Youtube:

algorithm:

*/

/*

39. Combination Sum

Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates where the chosen
numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations
that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

*/