#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles)
    {
        // TC: O(n)
        // SC: O(n)

        long long count = 0;
        unordered_map<double, double> map;
        int n = rectangles.size();
        for (int i = 0; i < n; i++)
        {
            double ratio = rectangles[i][0] / (double)rectangles[i][1];
            map[ratio]++;
        }
        for (auto &&i : map)
        {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl
             << endl;
        for (auto &&i : map)
        {
            long long temp = i.second;
            if (temp > 1)
            {
                long long sum = (temp * (temp - 1)) / 2;
                count += sum;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> rectangles{{4, 8}, {3, 6}, {10, 20}, {15, 30}};
    vector<vector<int>> rectangles{{4, 5}, {7, 8}};
    cout << "No of Interchangable Rectangles : " << s.interchangeableRectangles(rectangles);
    return 0;
}

/*

link: 
 
leetcode: https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/

Youtube:

algorithm: 

- refer 1512 LC
- use nCr formula
- here we know we have to find the combinations of 2, hence simplifying nCr formula,
  we get n(n*1)/2, which is same as sum 1....n.

*/