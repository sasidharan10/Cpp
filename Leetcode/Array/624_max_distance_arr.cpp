#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force - finding all possible pairs, and returning max diff.
    int maxDistance2(vector<vector<int>> &arrays)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = arrays.size();
        int maxDiff = 0;
        for (int i = 0; i < n; i++)
        {
            int firstElm = arrays[i][0];
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int sz = arrays[j].size();
                int lastElement = arrays[j][sz - 1];
                maxDiff = max(maxDiff, abs(firstElm - lastElement));
            }
        }
        return maxDiff;
    }

    // Optimal - greedy
    int maxDistance(vector<vector<int>> &arrays)
    {
        // TC: O(n)
        // SC: O(1)

        int n = arrays.size();

        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();
        int maxDiff = 0;

        for (int i = 1; i < n; i++)
        {
            int currMin = arrays[i][0];
            int currMax = arrays[i].back();

            maxDiff = max({maxDiff, abs(maxVal - currMin), abs(currMax - minVal)});

            maxVal = max(maxVal, currMax);
            minVal = min(minVal, currMin);
        }
        return maxDiff;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> nums{{1, 2, 3}, {4, 5}, {1, 2, 3}};
    vector<vector<int>> nums{{1, 4}, {2, 3}};
    cout << "Result: " << s.maxDistance(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-distance-in-arrays

Youtube: https://www.youtube.com/watch?v=OO6i7g3it4Q

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Greedy/Maximum%20Distance%20in%20Arrays.cpp

algorithm:

- Brute Force Approach:

- Find all possible pairs and then return max diff among them.

- Optimal Approach:

- As we traverse the array, we keep track of maxVal and minVal. Then we try ti find the diff
  with the currMin and currMax val, and update the maxDiff.
- Note that, maxVal and minVal stores the maximum and minimum values we have seen so far. Lets say
  we are at the ith index, then maxVal and minVal has the values updated till (i - 1)th index. Then 
  we compare it with the i'th array values. This ensures, we never compute the maxDiff, by picking 
  both values from the same array. After computing the maxdiff, we update maxVal and minVal.

*/

/*

624. Maximum Distance in Arrays

You are given m arrays, where each array is sorted in ascending order.
You can pick up two integers from two different arrays (each array picks one) and calculate the
distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array
and pick 5 in the second array.

Example 2:

Input: arrays = [[1],[1]]
Output: 0

Constraints:

m == arrays.length
2 <= m <= 10^5
1 <= arrays[i].length <= 500
-10^4 <= arrays[i][j] <= 10^4
arrays[i] is sorted in ascending order.
There will be at most 10^5 integers in all the arrays.

*/

/*
************* Java Code **************

    public static int maxDistance(List<List<Integer>> arrays) {
        int n = arrays.size();

        int minVal = arrays.get(0).get(0);
        int maxVal = arrays.get(0).get(arrays.get(0).size() - 1);
        int maxDiff = 0;

        for (int i = 1; i < n; i++)
        {
            int currMin = arrays.get(i).get(0);
            int currMax = arrays.get(i).get(arrays.get(i).size() - 1);

            maxDiff = Math.max(maxDiff, Math.max(Math.abs(maxVal - currMin), Math.abs(currMax - minVal)));

            maxVal = Math.max(maxVal, currMax);
            minVal = Math.min(minVal, currMin);
        }
        return maxDiff;
    }

*/