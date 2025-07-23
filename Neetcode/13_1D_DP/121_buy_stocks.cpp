#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // TC: O(n)
        // SC: O(1)

        int maxProfit = 0;
        int minPrice = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
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

- Keep track of the minimum element, and find the max profit.

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