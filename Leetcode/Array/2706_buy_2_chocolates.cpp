#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = prices.size();
        int sum = 0;
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (prices[i] < min1)
            {
                min2 = min1;
                min1 = prices[i];
            }
            else if (prices[i] < min2)
                min2 = prices[i];
        }
        sum = min1 + min2;
        if (sum > money)
            return money;
        return money - sum;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 2};
    int money = 3;
    cout << "Result: " << s.buyChoco(nums, money) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/buy-two-chocolates

Youtube:

algorithm:

*/

/*

2706. Buy Two Chocolates

You are given an integer array prices representing the prices of various 
chocolates in a store. You are also given a single integer money, 
which represents your initial amount of money.

You must buy exactly two chocolates in such a way that you still have 
some non-negative leftover money. You would like to minimize the sum 
of the prices of the two chocolates you buy.

Return the amount of money you will have leftover after buying the two 
chocolates. If there is no way for you to buy two chocolates without 
ending up in debt, return money. Note that the leftover must be non-negative.

Example 1:

Input: prices = [1,2,2], money = 3
Output: 0
Explanation: Purchase the chocolates priced at 1 and 2 units respectively. 
You will have 3 - 3 = 0 units of money afterwards. Thus, we return 0.

Example 2:

Input: prices = [3,2,3], money = 3

Output: 3
Explanation: You cannot buy 2 chocolates without going in debt, so we return 3.

*/