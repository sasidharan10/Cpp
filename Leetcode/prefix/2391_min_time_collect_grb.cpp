#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int time = 0, mi = 0, gi = 0, pi = 0;
        int n = garbage.size();
        int k = travel.size();
        for (int i = 0; i < n; i++)
        {
            int m = garbage[i].length();
            for (int j = 0; j < m; j++)
            {
                if (garbage[i][j] == 'M')
                    mi = i;

                else if (garbage[i][j] == 'G')
                    gi = i;

                else if (garbage[i][j] == 'P')
                    pi = i;
                time++;
            }
        }
        for (int i = 1; i < k; i++)
        {
            travel[i] += travel[i - 1];
        }
        int ans = time;
        if (gi > 0)
            ans += travel[gi - 1];
        if (mi > 0)
            ans += travel[mi - 1];
        if (pi > 0)
            ans += travel[pi - 1];
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> garbage{"MMM", "PGM", "GP"};
    vector<int> travel{3, 10};
    cout << "Minimum Amount of Time to Collect Garbage: " << s.garbageCollection(garbage, travel) << endl;
    return 0;
}

/*

2391. Minimum Amount of Time to Collect Garbage

You are given a 0-indexed array of strings garbage where garbage[i] represents the 
assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 
'P' and 'G' representing one unit of metal, paper and glass garbage respectively. 
Picking up one unit of any type of garbage takes 1 minute.

You are also given a 0-indexed integer array travel where travel[i] is the number 
of minutes needed to go from house i to house i + 1.

There are three garbage trucks in the city, each responsible for picking up 
one type of garbage. Each garbage truck starts at house 0 and must visit each 
house in order; however, they do not need to visit every house.

Only one garbage truck may be used at any given moment. While one truck is 
driving or picking up garbage, the other two trucks cannot do anything.

Return the minimum number of minutes needed to pick up all the garbage.



Example 1:

Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21
Explanation:
The paper garbage truck:
1. Travels from house 0 to house 1
2. Collects the paper garbage at house 1
3. Travels from house 1 to house 2
4. Collects the paper garbage at house 2
Altogether, it takes 8 minutes to pick up all the paper garbage.
The glass garbage truck:
1. Collects the glass garbage at house 0
2. Travels from house 0 to house 1
3. Travels from house 1 to house 2
4. Collects the glass garbage at house 2
5. Travels from house 2 to house 3
6. Collects the glass garbage at house 3
Altogether, it takes 13 minutes to pick up all the glass garbage.
Since there is no metal garbage, we do not need to consider the metal garbage truck.
Therefore, it takes a total of 8 + 13 = 21 minutes to collect all the garbage.
Example 2:

Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
Output: 37
Explanation:
The metal garbage truck takes 7 minutes to pick up all the metal garbage.
The paper garbage truck takes 15 minutes to pick up all the paper garbage.
The glass garbage truck takes 15 minutes to pick up all the glass garbage.
It takes a total of 7 + 15 + 15 = 37 minutes to collect all the garbage.

*/

/*

link:

leetcode: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

Youtube: https://www.youtube.com/watch?v=SGJMTu9SZHs

algorithm:

- Total time taken to take each garbage is 1, so we will increment time
  by 1, everytime, we getany of the 1 garbage.
- Find the maximum index until which each truck need to go,
  then using prefix sum, we just add the time taken by each truck
  to reach to collect the garbage.
- We dont need to visit further house, if we dont find have any garbage
  present further of that type. so no need to travel time for that truck,
  since it didnt need to travel.
*/