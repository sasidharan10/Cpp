#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute - gives TLE
    vector<int> successfulPairs2(vector<int> &spells, vector<int> &potions, long long success)
    {
        // TC: O(n*m)
        // SC: O(n) for storing answer

        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((long long)spells[i] * potions[j] >= success)
                {
                    ans[i] = m - j;
                    break;
                }
            }
        }
        return ans;
    }

    // Optimal using Binary Search
    int customLowerBound(int m, int target, long long success, vector<int> &potions)
    {
        int low = 0, high = m - 1;
        int index = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long prod = (long long)potions[mid] * target;
            if (prod >= success)
            {
                index = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (index == -1)
            return 0;
        else
            return m - index;
    }
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        // TC: O(mlogm) + O(n*logm)
        // SC: O(n) for storing answer

        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[i] = customLowerBound(m, spells[i], success, potions);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> spells = {5, 1, 3}, potions = {1, 2, 3, 4, 5};
    int success = 7;
    vector<int> ans = s.successfulPairs2(spells, potions, success);
    cout << "No of Successful Pairs of Spells and Potions: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/successful-pairs-of-spells-and-potions

Youtube:

algorithm:

- Brute Force

- we have to take prod of each spell[i] with every potion[j] and
  check if spells[i] * potions[j] >= success, if yes, then cnt++.
- To reduce complexity, we sort potion[j], so once we encounter a element
  satisfying the condition, we know all elements after that element
  will also satisfy that condition, and we take m - index as count.

- Optimal Approach

- using same method, but instead we use binary search to find that
  index. and reducing the complexity by logm.

*/

/*

2300. Successful Pairs of Spells and Potions

You are given two positive integer arrays spells and potions, of
length n and m respectively, where spells[i] represents the strength
of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is
considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the
number of potions that will form a successful pair with the ith spell.

Example 1:

Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.

Example 2:

Input: spells = [3,1,2], potions = [8,5,8], success = 16
Output: [2,0,2]
Explanation:
- 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
- 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful.
- 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful.
Thus, [2,0,2] is returned.

*/