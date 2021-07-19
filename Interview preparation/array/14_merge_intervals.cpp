#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    vector<vector<int>> ans;                  // to store all the non-overlapping intervals
    vector<int> temp;                         // to store each intervals(row) and compare with intervals
    sort(intervals.begin(), intervals.end()); // intervals will be sorted w.r.t to rows
    temp = intervals[0];                      //first interval(row)
    for (auto it : intervals)
    {
        if (temp[1] >= it[0])
        {
            temp[1] = max(temp[1], it[1]);
        }
        else
        {
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    return ans;
}
int main()
{
    // vector<vector<int>> v =  { {6,8}, {1,9}, {2,4}, {4,7} };
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    v = mergeIntervals(v);
    cout << "Non-Overlapping pairs are : ";
    for (vector<int> vec : v)
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