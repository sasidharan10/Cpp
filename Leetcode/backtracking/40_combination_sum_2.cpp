#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void findCombination(int index, vector<int> v, vector<int> &temp, vector<vector<int>> &ans, int target)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = index; i < v.size(); i++)
    {
        if (i > index && v[i] == v[i - 1]) // refer below
            continue;                      // ignore duplicates
        if (v[i] > target)
            break;
        temp.push_back(v[i]);
        findCombination(i + 1, v, temp, ans, target - v[i]);
        temp.pop_back();
    }
}
void calCombination(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    findCombination(0, candidates, temp, ans, target);
    cout << "Combinations: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    calCombination(candidates, target);
    return 0;
}

/*

link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/Combination%20Sum%20II.cpp

leetcode: https://leetcode.com/problems/combination-sum-ii/

Youtube: https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=12

Youtube MIK: https://www.youtube.com/watch?v=bfKwLi6jtDk

algorithm:

-   i>index (or i!=index) is used, so that we can pick the element first time without
    checking  this condition "v[i] == v[i - 1]".
    eg: [1,1,1,2,2]
    as we go down the recursion call, we pick each one position till n-1.
    suppose I picked 1 from 0th index and now i am picking elements for 1st index,
    so in that case, i should not check my 1st index element with 0th index, as it was already picked,
    but due to this condition "v[i] == v[i - 1]", it will check and we might skip that element.
    so we use "i>index (or i!=index)" to skip that condition for first time.
*/

/*

40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target
number (target), find all unique combinations in candidates
where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]

*/

/*
************* Java Code **************

    public static void findCombination(int index, int[] v, List<Integer> temp, List<List<Integer>> ans, int target) {
        if (target == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        for (int i = index; i < v.length; i++) {
            if (i > index && v[i] == v[i - 1]) // refer below
                continue;
            if (v[i] > target)
                break;
            temp.add(v[i]);
            findCombination(i + 1, v, temp, ans, target - v[i]);
            temp.remove(temp.size() - 1);
        }
    }

    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(candidates);
        findCombination(0, candidates, temp, ans, target);
        return ans;
    }

*/