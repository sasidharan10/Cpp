#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maxOnes1(vector<vector<int>> v)
{
    // Time : O(n*m)
    // Space : O(1)

    int maxRow = 0;
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < v.size(); i++)
    {
        count = 0;
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == 1)
                count++;
            if (count > maxCount)
            {
                count = maxCount;
                maxRow = i;
            }
        }
    }
    return maxRow;
}
int maxOnes2(vector<vector<int>> v)
{
    // Time : O(n+m)
    // Space : O(1)

    int n = v.size();    // row
    int m = v[0].size(); // column
    int maxRow = -1;
    int i = 0;
    int j = m - 1;
    while (i < n && j >= 0)
    {
        if (v[i][j] == 1)
        {
            j--;
            maxRow = i;
        }

        else if (v[i][j] == 0)
        {
            i++;
        }
    }
    return maxRow;
}
int main()
{
    vector<vector<int>> v{{0, 0, 0, 1},
                          {0, 1, 1, 1},
                          {1, 1, 1, 1},
                          {0, 0, 0, 0}};

    // cout << "Row with maximum 1s : " << maxOnes1(v)<<endl;
    cout << "Row with maximum 1s : " << maxOnes2(v) << endl;
}