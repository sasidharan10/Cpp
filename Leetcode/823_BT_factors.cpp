#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<long long, long long> map;
        for (int i = 0; i < n; i++)
        {
            map[arr[i]] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int root = arr[i];
                int left = arr[j];
                int right = root / left;
                if (root % left == 0 && map.find(right) != map.end())
                {
                    map[root] += (map[left] * map[right]) % mod;
                }
            }
        }
        long long cnt = 0;
        for (auto &&i : map)
        {
            cnt += i.second;
            cnt %= mod;
        }
        return cnt % mod;
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 4, 5, 10};
    cout << "Binary Trees With Factors: " << s.numFactoredBinaryTrees(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/binary-trees-with-factors

Youtube: https://www.youtube.com/watch?v=D2GnunVezNA

algorithm:

*/
