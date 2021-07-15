#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> spiral(vector<vector<int>> v)
{
    vector<int> ans;
    int row = v.size();
    int col = v[0].size();
    int top = 0;
    int right = col - 1;
    int bottom = row - 1;
    int left = 0;
    int direction = 0;
    while (top <= bottom && left <= right)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(v[top][i]);
            }
            top++;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(v[i][right]);
            }
            right--;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(v[bottom][i]);
            }
            bottom--;
        }
        else if (direction == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(v[i][left]);
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
    return ans;
}
int main()
{
    vector<vector<int>> a{{1, 2, 3, 4},
                          {5, 6, 7, 8},
                          {9, 10, 11, 12},
                          {13, 14, 15, 16}};
    vector<int> ans = spiral(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}