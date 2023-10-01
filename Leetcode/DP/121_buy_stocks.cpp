#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
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

*/