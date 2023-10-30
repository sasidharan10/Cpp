#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        // TC: O(log2(buckets))
        // SC: O(1)

        int trials = (minutesToTest / minutesToDie);
        int t = trials + 1;
        int pigs = 0;
        while (pow(t, pigs) < buckets)
        {
            pigs++;
        }
        return pigs;
    }
};
int main()
{
    Solution s;
    int buckets = 4, minutesToDie = 15, minutesToTest = 30;
    cout << "Minimum no of pigs required: " << s.poorPigs(buckets, minutesToDie, minutesToTest) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/poor-pigs/

Youtube: https://www.youtube.com/watch?v=YQJLNxveyKg

algorithm:

*/