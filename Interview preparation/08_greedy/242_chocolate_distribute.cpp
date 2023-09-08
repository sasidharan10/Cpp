#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        int i = 0;
        int j = m - 1;
        sort(a.begin(), a.end());
        int mini = INT_MAX;
        while (j < a.size())
        {
            int diff = a[j] - a[i];
            mini = min(mini, diff);
            i++;
            j++;
        }
        return mini;
    }
};
int main()
{
    Solution s;
    vector<long long> nums{3, 4, 1, 9, 56, 7, 9, 12};
    long long n = 8, m = 5;
    cout << "Min diffference between max and min chocolates: " << s.findMinDiff(nums, n, m);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

leetcode: 

Youtube: 

algorithm: 

*/