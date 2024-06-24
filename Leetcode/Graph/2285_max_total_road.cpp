#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal - using degree and assiging value greedily
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        // TC: O(E) + O(nlogn) + O(n)
        // SC: O(n)

        int m = roads.size();
        vector<int> outDegree(n, 0);
        for (int i = 0; i < m; i++)
        {
            outDegree[roads[i][0]]++;
            outDegree[roads[i][1]]++;
        }
        sort(outDegree.begin(), outDegree.end(), greater<>());
        long long res = 0;
        long long val = n;
        for (int i = 0; i < n; i++)
        {
            res += outDegree[i] * val;
            val--;
        }
        return res;
    }
};
int main()
{
    Solution s;
    int n = 5;
    vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    cout << "Result: " << s.maximumImportance(n, roads) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-total-importance-of-roads

Youtube: https://www.youtube.com/watch?v=p4y_rQeB2mg

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Maximum%20Total%20Importance%20of%20Roads.cpp

algorithm:

- Optimal Approach:

- maximum total importance of all roads possible
- The cities(nodes) are denoted a from 0 - n-1.
- We ahve to assign those cities with new values, from 1 - n, such that we get the 
  "maximum total importance of all roads possible".
- The "Importance" is calculated by the sum of values of the two cities it connects.
- So to get the maximum importance, we have to assign the max values to those cities
  which have most edges.
- hence we calculate the degree of all nodes, and assign the max values to the nodes
  havig max degree.

*/

/*

2285. Maximum Total Importance of Roads

You are given an integer n denoting the number of cities in a country. The cities are
numbered from 0 to n - 1.

You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there
exists a bidirectional road connecting cities ai and bi.

You need to assign each city with an integer value from 1 to n, where each value can only
be used once. The importance of a road is then defined as the sum of the values of the two
cities it connects.

Return the maximum total importance of all roads possible after assigning the values optimally.

Example 1:

Input: n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
Output: 43
Explanation: The figure above shows the country and the assigned values of [2,4,5,3,1].
- The road (0,1) has an importance of 2 + 4 = 6.
- The road (1,2) has an importance of 4 + 5 = 9.
- The road (2,3) has an importance of 5 + 3 = 8.
- The road (0,2) has an importance of 2 + 5 = 7.
- The road (1,3) has an importance of 4 + 3 = 7.
- The road (2,4) has an importance of 5 + 1 = 6.
The total importance of all roads is 6 + 9 + 8 + 7 + 7 + 6 = 43.
It can be shown that we cannot obtain a greater total importance than 43.

Example 2:

Input: n = 5, roads = [[0,3],[2,4],[1,3]]
Output: 20
Explanation: The figure above shows the country and the assigned values of [4,3,2,5,1].
- The road (0,3) has an importance of 4 + 5 = 9.
- The road (2,4) has an importance of 2 + 1 = 3.
- The road (1,3) has an importance of 3 + 5 = 8.
The total importance of all roads is 9 + 3 + 8 = 20.
It can be shown that we cannot obtain a greater total importance than 20.

Constraints:

2 <= n <= 5 * 104
1 <= roads.length <= 5 * 104
roads[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no duplicate roads.

*/

/*
************* Java Code **************



*/