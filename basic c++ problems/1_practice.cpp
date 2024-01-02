#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums{1, 3, 4, 1, 2, 3, 1};
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    cout << mp.size() << endl;
    while (mp.size())
    {
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second <= 0)
            {
                mp.erase(it->first);
                continue;
            }
            if (it->second > 0)
            {
                cout << it->first << " ";
                it->second--;
            }
        }
        // break;
        cout << endl;
    }

    return 0;
}