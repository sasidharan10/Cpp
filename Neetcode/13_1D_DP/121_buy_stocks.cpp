#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int maxProfit(vector<int> &prices)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = prices.size();
        int maxProfit = 0;

        // Try buying at every day i
        for (int i = 0; i < n - 1; i++)
        {
            // Try selling at every day j > i
            for (int j = i + 1; j < n; j++)
            {
                // Calculate profit if bought at i and sold at j
                int profit = prices[j] - prices[i];

                // Update maxProfit if this is better
                if (profit > maxProfit)
                {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }

    // Optimal Approach
    int maxProfit(vector<int> &prices)
    {
        // TC: O(n) – single pass through the array
        // SC: O(1) – constant extra space

        int maxProfit = 0;        // stores the maximum profit found so far
        int minPrice = prices[0]; // stores the minimum price seen so far (best day to buy)

        for (int i = 0; i < prices.size(); i++)
        {
            // update the minimum price if a lower price is found
            minPrice = min(minPrice, prices[i]);

            // calculate potential profit by selling on day i
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};
int main()
{
    Solution s;
    vector<int> nums{7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << s.maxProfit(nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Youtube: https://www.youtube.com/watch?v=excAOvwF_Wk&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=36&pp=iAQB

Code Link:

algorithm:

- Brute Force Approach:

- find all combinations.
- TC: O(n^2)

- Optimal Approach:

- Track the lowest price seen so far (minPrice) — the best day to buy.
- On each day i, compute the profit if selling on that day: prices[i] - minPrice.
- Update maxProfit if the current profit is greater than the previously recorded max.
- Update minPrice if a new lower price is found.
- Only one pass through the array is needed.

*/

/*

121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different
day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4

*/

/*
************* Java Code **************

    public static int maxProfit(int[] prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        for (int i = 0; i < prices.length; i++) {
            minPrice = Math.min(minPrice, prices[i]);
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }

*/