#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // TC: O(nLogn) + O(2n)
        // SC: O(1) storing answers

        int maxi = 0, mini = 0;
        sort(candies, candies + N);
        int buy = 0, free = N - 1;
        while (buy <= free)
        {
            maxi += candies[buy++];
            free = free - K;
        }
        buy = N - 1;
        free = 0;
        while (free <= buy)
        {
            mini += candies[buy--];
            free = free + K;
        }
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};
int main()
{
    Solution s;
    int candies[] = {3, 2, 1, 4};
    int n = 4;
    int k = 2;
    cout << "Max Meeting in the room: " << endl;
    vector<int> ans = s.candyStore(candies, n, k);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

leetcode: 

Youtube: 

algorithm: 

*/