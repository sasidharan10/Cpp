#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(pair<int, string> &p1, pair<int, string> &p2)
    {
        if (p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second > p2.second;
    }
};
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            mp[words[i]]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto &&it : mp)
        {
            pq.push({it.second, it.first});
        }
        vector<string> ans;
        while (k > 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> words{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 4;
    vector<string> ans = s.topKFrequent(words, k);
    cout << "Top K Frequent Words: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/top-k-frequent-words/description/

Youtube:

algorithm:

*/