#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute
    vector<int> fullBloomFlowers3(vector<vector<int>> &flowers, vector<int> &people)
    {
        // TC: O(n^2)
        // SC: O(n)

        vector<pair<int, int>> map;
        for (int i = 0; i < people.size(); i++)
        {
            map.push_back({people[i], 0});
        }
        for (int i = 0; i < flowers.size(); i++)
        {
            int start = flowers[i][0];
            int end = flowers[i][1];
            for (auto &&i : map)
            {
                int person = i.first;
                if (person >= start && person <= end)
                    i.second++;
            }
        }
        vector<int> ans;
        for (auto &&i : map)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
    // better
    vector<int> fullBloomFlowers2(vector<vector<int>> &flowers, vector<int> &people)
    {
        // TC: O(nlogn) + 2*O(mlogm)
        // SC: o(n) + 2*O(mlogm)

        multimap<int, int> mp;
        vector<int> ans(people.size(), 0);
        for (int i = 0; i < people.size(); i++)
        {
            mp.insert({people[i], i});
        }
        cout << endl;
        priority_queue<int, vector<int>, greater<>> start;
        priority_queue<int, vector<int>, greater<>> end;
        for (int i = 0; i < flowers.size(); i++)
        {
            start.push(flowers[i][0]);
            end.push(flowers[i][1]);
        }
        cout << endl;
        int count = 0;
        for (auto &&i : mp)
        {
            int person = i.first;
            int index = i.second;
            // counting the full bloom flowers
            while (!start.empty() && start.top() <= person)
            {
                start.pop();
                count++;
            }
            // removing the flowers out of range
            while (!end.empty() && end.top() < person)
            {
                end.pop();
                count--;
            }
            ans[index] = count;
        }
        return ans;
    }

    // Optimal
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        // TC: O(nlogn) + O(mlogm)
        // SC: o(n) + O(mlogm)

        multimap<int, int> mp;
        sort(flowers.begin(), flowers.end());
        vector<int> ans(people.size(), 0);
        for (int i = 0; i < people.size(); i++)
        {
            mp.insert({people[i], i});
        }
        priority_queue<int, vector<int>, greater<>> st;
        int j = 0;
        for (auto &&i : mp)
        {
            int person = i.first;
            int index = i.second;
            // counting the full bloom flowers
            while (j < flowers.size() && flowers[j][0] <= person)
            {
                st.push(flowers[j][1]);
                j++;
            }
            // removing the flowers out of range
            while (!st.empty() && st.top() < person)
            {
                st.pop();
            }
            ans[index] = st.size();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> flowers{{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> people{2, 3, 7, 11};
    // vector<vector<int>> flowers{{1, 10}, {3, 3}};
    // vector<int> people{3, 3, 2};
    vector<int> ans = s.fullBloomFlowers(flowers, people);
    cout << "No of Flowers, people saw while Full Blossom: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-flowers-in-full-bloom

Youtube: https://www.youtube.com/watch?v=zY3Uty9IwvY

algorithm:

*/