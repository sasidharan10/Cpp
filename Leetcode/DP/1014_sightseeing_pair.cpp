#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    int maxScoreSightseeingPair(vector<int> &values)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = values.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int temp = values[i] + values[j] + i - j;
                maxi = max(maxi, temp);
            }
        }
        return maxi;
    }

    // Optimal
    int maxScoreSightseeingPair2(vector<int> &values)
    {
        // TC: O(n)
        // SC: O(1)
    }
};
int main()
{
    Solution s;
    vector<int> nums{8, 1, 5, 2, 6};
    cout << "Result: " << s.maxScoreSightseeingPair(nums) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

1014. Best Sightseeing Pair

You are given an integer array values where values[i] represents the
value of the ith sightseeing spot. Two sightseeing spots i and j have
 a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j:
the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

Example 2:

Input: values = [1,2]
Output: 2

*/
