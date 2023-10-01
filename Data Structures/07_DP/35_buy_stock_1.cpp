#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices)
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
int main()
{
    vector<int> nums{7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maximumProfit(nums);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/stocks-are-profitable_893405

leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Youtube: https://www.youtube.com/watch?v=excAOvwF_Wk&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=36&pp=iAQB

*/