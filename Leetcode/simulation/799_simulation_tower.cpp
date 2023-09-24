#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> cup(101, vector<double>(101, 0));
        cup[0][0] = poured;
        for (int i = 0; i < query_row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (cup[i][j] > 1)
                {
                    cup[i + 1][j] += ((cup[i][j] - 1) / 2.0);
                    cup[i + 1][j + 1] += ((cup[i][j] - 1) / 2.0);
                    cup[i][j] = 1;
                }
            }
        }
        return cup[query_row][query_glass];
    }
    double champagneTower1(int poured, int query_row, int query_glass)
    {
        vector<double> prev(101, 0);
        prev[0] = poured;
        for (int i = 0; i <= query_row; i++)
        {
            vector<double> cur(101, 0);
            for (int j = 0; j <= i; j++)
            {
                if (prev[j] > 1)
                {
                    cur[j] += ((prev[j] - 1) / 2.0);
                    cur[j + 1] += ((prev[j] - 1) / 2.0);
                    prev[j] = 1;
                }
            }
            if (i != query_row)
                prev = cur;
        }
        return prev[query_glass];
    }
};
int main()
{
    Solution s;
    int poured = 2, query_row = 1, query_glass = 1;
    cout << "Amount of champagne in ith, jth cup: " << s.champagneTower1(poured, query_row, query_glass) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/champagne-tower/description/

Youtube: https://www.youtube.com/watch?v=POuK_Ng5INo

algorithm:

*/