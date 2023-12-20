#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int calCapacity(int cap, vector<int> &weights)
    {
        int n = weights.size();
        int days = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + weights[i] <= cap)
            {
                sum += weights[i];
            }
            else
            {
                days++;
                sum = weights[i];
            }
        }
        return days;
    }
    int leastWeightCapacity(vector<int> &weights, int d)
    {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int daysTaken = calCapacity(mid, weights);
            if (daysTaken <= d)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    cout << "Result: " << s.leastWeightCapacity(nums, d) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/capacity-to-ship-packages-within-d-days_1229379

leetcode: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

Youtube: https://www.youtube.com/watch?v=MG-Ac4TAvTY&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF

algorithm:

- We need to calculate the minimum capacity of the ship, that can
  be loaded for d days.
- Hence, the minimum capacity can be maximum weight in the array,
  having that as capacity, ensures each package can be shipped
  in each day.
- Maximum capacity will be the sum of all packages weights, since
  that means, we can ship all packages at once.
- Keeping this range, we find the mid, and keeping it as capacity,
  we find the no of days to complete the shipment and if it takes <= d days
  we update that capacity as answer. and move to left to find even less capacity.
- If greater, then we move right, to increase the capacity, so we can decrease
  no of days taken to fulfill the shipment.

*/

/*






*/