#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal
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
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int daysTaken = calCapacity(mid, weights);
            if (daysTaken <= days)
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
    int days = 5;
    cout << "Result: " << s.shipWithinDays(nums, days) << endl;
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

1011. Capacity To Ship Packages Within D Days

A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, 
we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the 
packages on the conveyor belt being shipped within days days.

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a 
ship of capacity 14 and splitting the packages into parts like 
(2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

*/