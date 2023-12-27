#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < n)
        {
            int sum = 0, maxi = INT_MIN;
            // int flag = -1;
            while (colors[i] == colors[j])
            {
                sum += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                // flag++;
                j++;
            }
            // if (flag > 0)
            ans += sum - maxi;
            i = j;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string colors = "abaac";
    vector<int> neededTime = {1, 2, 3, 4, 5};
    // string colors = "abc";
    // vector<int> neededTime = {1, 2, 3};
    cout << "Result: " << s.minCost(colors, neededTime) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-time-to-make-rope-colorful

Youtube:

algorithm:

- This can be solved by grreedy approach.
- similar to sliding window, we check for consecutive same color
  balloons, and traverse them.
- We know if multiple balloons of same color are placed consecutively,
  we have to remove every balloons, and only keep 1 balloon.
- The balloons removed should be having less neededTime[i], to reduce the
  overall time cost.
- Which means the balloon with max neededTime[i], will be kept in the array.
- Hence while we traverse through these window, we sum the overall neededTime[i]
  and subtract with maxi, to get the overall time needed to remove duplicate
  balloons.
- In case of 1 balloon, maxi == sum, hence it will not impact the answer.
- Or we can keep a flag variable, to check if there are more than 1 consecutive
  balloons of same color, if yes, we add the sum, else we ignore.

*/

/*






*/