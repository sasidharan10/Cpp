#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static int bitCount(int num)
    {
        int cnt = 0;
        while (num > 0)
        {
            cnt += num & 1;
            num >>= 1;
        }
        return cnt;
    }
    static bool cmp(int &a, int &b)
    {
        // TC: O(nlogn) *O(log2(num))
        // SC: O(1)

        int cntA = bitCount(a);
        int cntB = bitCount(b);
        if (cntA == cntB)
            return a < b;
        else
            return cntA < cntB;
    }
    static bool cmp2(int &a, int &b)
    {
        // TC: O(nlogn)
        // SC: O(1)

        // gets 1s bit count in O(1) TC
        int cntA = __builtin_popcount(a);
        int cntB = __builtin_popcount(b);
        if (cntA == cntB)
            return a < b;
        else
            return cntA < cntB;
    }
    vector<int> sortByBits(vector<int> &arr)
    {

        // sort(arr.begin(), arr.end(), cmp);
        sort(arr.begin(), arr.end(), cmp2);
        return arr;
    }
};
int main()
{
    Solution s;
    vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ans = s.sortByBits(nums);
    cout << "Array after sorting by 1s bit: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

Youtube: https://www.youtube.com/watch?v=2owpaafBIgw

algorithm:

*/