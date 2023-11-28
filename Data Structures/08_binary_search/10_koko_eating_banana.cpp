#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long getHours(int hrs, vector<int> &piles)
    {
        int n = piles.size();
        long long totalHrs = 0;
        for (int i = 0; i < n; i++)
        {
            totalHrs += ceil((double)piles[i] / (double)hrs);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxi = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxi;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long hrs = getHours(mid, piles);
            if (hrs <= h)
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
    vector<int> piles{30, 11, 23, 4, 20};
    int h = 6;
    cout << "Minimum amount of Banana's Koko can eat in 1 hr: " << s.minEatingSpeed(piles, h) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064

leetcode: https://leetcode.com/problems/koko-eating-bananas/

Youtube: https://www.youtube.com/watch?v=qyfekrNni90&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=13

algorithm:

*/


/*

875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has 
piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she 
chooses some pile of bananas and eats k bananas from that pile. If the 
pile has less than k bananas, she eats all of them instead and will not 
eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas 
before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

*/