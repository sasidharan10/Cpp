#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPlatform(int arr[], int dep[], int n)
    {
        // TC: O(2nlogn) + O(2n)
        // SC: O(1)

        sort(arr, arr + n);
        sort(dep, dep + n);

        int platform = 1;
        int result = 1;
        int i = 1, j = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                platform++;
                i++;
            }
            else
            {
                platform--;
                j++;
            }
            result = max(result, platform);
        }
        return result;
    }
};
int main()
{
    Solution s;
    int arr[]{900, 940, 950, 1100, 1500, 1800};
    int dep[]{910, 1200, 1120, 1130, 1900, 2000};
    int n = 6;
    cout << "Min Platform: " << s.findPlatform(arr, dep, n);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

leetcode:

Youtube: https://www.youtube.com/watch?v=dxVcMDI7vyI

algorithm:

*/