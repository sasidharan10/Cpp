#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
class Solution
{
public:
    static bool cmp(pair<double, Item> i1, pair<double, Item> i2)
    {
        return i1.first > i2.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, Item>> it;
        for (int i = 0; i < n; i++)
        {
            double perUnitValue = ((1.0 * arr[i].value) / arr[i].weight);
            it.push_back({perUnitValue, arr[i]});
        }
        sort(it.begin(), it.end(), cmp);
        double maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            if (it[i].second.weight > W)
            {
                maxProfit += W * it[i].first;
                break;
            }
            else
            {
                maxProfit += it[i].second.value;
                W = W - it[i].second.weight;
            }
        }
        return maxProfit;
    }
};
int main()
{
    Solution s;
    int n = 3;
    int w = 50;
    Item it[3];
    it[0].value = 60;
    it[1].value = 100;
    it[2].value = 120;
    it[0].weight = 10;
    it[1].weight = 20;
    it[2].weight = 30;
    cout << "Max profit: " << s.fractionalKnapsack(w, it, n) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

leetcode: 

Youtube: 

algorithm: 

*/