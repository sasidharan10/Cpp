#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int calcProfit1(int *a, int n)
{
    // O(n)

    // this solution is for multiple buying and selling of stocks if possible
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
            profit += a[i] - a[i - 1];
    }
    return profit;
}
int calcProfit2(int *a, int n)
{
    // O(n)
    
    // TC: O(n)
    // SC: O(1)
    
    // In this solution, the stock is bought and sold only 1 time 
    // Global Maxima - Global Minima
    int minPrice=INT_MAX;
    int maxProfit=0;
    for (int i = 0; i < n; i++)
    {
        minPrice=min(a[i],minPrice);
        maxProfit=max(maxProfit,a[i]-minPrice);
    }
    return maxProfit;
}
int main()
{
    int a[] = {7, 1, 5, 3, 6, 4};
    // int a[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Max Profit (n transactions) : " << calcProfit1(a, n) << endl;
    cout << "Max Profit (only 1 transaction) : " << calcProfit2(a, n) << endl;
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

*/