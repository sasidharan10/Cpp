#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        vector<int>temp = intervals[0];
        for (auto i :intervals)
        {
            if(temp[1] >= i[0])
            {
                temp[1]=max(temp[1], i[1]);
            }
            else
            {
                ans.push_back(temp);
                temp=i;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans=s.merge(v);
    cout << "Non-Overlapping pairs are : ";
    for (vector<int> vec : ans)
    {
        cout << "{ ";
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << "}, ";
    }
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/merge-intervals/description/

*/