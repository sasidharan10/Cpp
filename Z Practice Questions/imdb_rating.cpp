#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getmaxincrements(int n, vector<int> &ratings)
    {
        if (n <= 1)
            return 0;

        map<int, int> freq;
        for (int rating : ratings)
        {
            freq[rating]++;
        }

        if (freq.size() == 1)
            return 0;

        int cnt = 0;
        map<int, int>::iterator prev = freq.begin();
        for (auto it = next(freq.begin()); it != freq.end(); ++it)
        {
            cnt += min(prev->second, it->second);
            prev = it;
        }

        return cnt;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, 1, 3};
    // int n = 3;
    vector<int> nums{2, 1, 1, 2};
    int n = 4;
    // vector<int> nums{2,3,1,5,4};
    // int n = 5;
    cout << "Result: " << s.getmaxincrements(n, nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/discuss/post/6645628/tough-amazon-online-assesment-coding-cha-uikp/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*






*/

/*
************* Java Code **************

    public static int getmaxincrements(int n, int[] ratings) {
        if (n <= 1)
            return 0;

        TreeMap<Integer, Integer> freq = new TreeMap<>();
        for (int rating : ratings) {
            freq.put(rating, freq.getOrDefault(rating, 0) + 1);
        }

        if (freq.size() == 1)
            return 0;

        int cnt = 0;
        Integer prevKey = null;
        for (Integer key : freq.keySet()) {
            if (prevKey != null) {
                cnt += Math.min(freq.get(prevKey), freq.get(key));
            }
            prevKey = key;
        }

        return cnt;
    }

*/