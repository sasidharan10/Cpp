#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    // Brute force
    int maxScoreSightseeingPair3(vector<int>& values) {
        // TC: O(n^2)
        // SC: O(1)
        
        int n = values.size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = values[i] + values[j] - j + i;
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }

    // better - using heap as prefix, to get the max (values[i] + i)
    int maxScoreSightseeingPair2(vector<int>& values) {
        // TC: O(nlogn)
        // SC: O(n)
        
        int n = values.size();
        priority_queue<int, vector<int>, less<int>>pq;
        pq.push(values[0] + 0);
        int maxi = 0;
        for (int j = 1; j < n; j++)
        {
            int x = values[j] - j;
            int y = pq.top();
            maxi = max(x + y, maxi);
        }
        return maxi;
    }

    // Optimal - using prefix array, to get the max (values[i] + i)
    int maxScoreSightseeingPair(vector<int>& values) {
        // TC: O(n)
        // SC: O(n)
        
        int n = values.size();
        vector<int>prefix(n, 0);
        prefix[0] = values[0] + 0;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], values[i] + i);
        }
        int maxi = 0;
        for (int j = 1; j < n; j++)
        {
            int x = values[j] - j;
            int y = prefix[j - 1];
            maxi = max(x + y, maxi);
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    vector<int> nums{8,1,5,2,6};
    cout << "Result: " <<s.maxScoreSightseeingPair(nums)<< endl;
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/best-sightseeing-pair

Youtube: https://www.youtube.com/watch?v=eQ1TdlglnY0

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Best%20Sightseeing%20Pair.cpp

algorithm: 

- Brute Force Approach:

- Find all possible pairs, and find the max(values[i] + values[j] + i - j).

- Optimal Approach:

- We can re write the formula as (values[i] + i) + (values[j] - j).
- usng a prefix array, we can store max(values[i] + i)) until i.
- then we can traverse through the array, and add (values[j] - j) and update maxi.

*/

/*

1014. Best Sightseeing Pair

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. 
Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of 
the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
Example 2:

Input: values = [1,2]
Output: 2
 

Constraints:

2 <= values.length <= 5 * 10^4
1 <= values[i] <= 1000

*/

/*   
************* Java Code **************



*/