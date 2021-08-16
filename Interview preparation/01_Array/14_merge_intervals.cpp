#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    // time : O(nlogn) + O(n) [for sotring and traversing through the intervals]
    // space : O(n)

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

/*

1) {1, 3}, {2, 6}, {8, 10}, {15, 18} => { 1 6 }, { 8 10 }, { 15 18 }
2) {6,8}, {1,9}, {2,4}, {4,7} => { 1 9 }

Problem : 
- here we have to find intervals without any overlapping. If overlapping occurs, we have merge those 
  intervals and return all non-overlapping intervals.

Solution : 
- we can compare the end of first(3 int {1,3}) interval with start of second interval(2 in {2,6}),
  if start is less(2<3), then overlapping of intevals exist, so we have to merge it.
- for merging, we can find max of both ends of intervals, that will be the end of new interval.

*/