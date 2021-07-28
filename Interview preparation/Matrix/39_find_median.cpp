#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int findMedian1(vector<vector<int>>v)
{
    // Time : O(n*mlog(n*m))
    // Space : O(n+m)

    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            ans.push_back(v[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    return ans[ans.size()/2];
}
int main()
{
    vector<vector<int>> v { {1,3,5}, {2,6,9}, {3,6,9} };
    cout << "Median : " << findMedian1(v) << endl;
    return 0;
}