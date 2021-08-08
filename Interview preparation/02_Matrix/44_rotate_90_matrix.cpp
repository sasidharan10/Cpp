#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void rotateMatrix1(vector<vector<int>> v)
{
    // Time : O(n^2)
    // Space : O(n^2)

    int row = v.size();
    int col = v[0].size();
    int k, l;
    vector<vector<int>> ans(row, vector<int>(col, 0));
    for (int i = 0, k = col - 1; i < row; i++, k--)
    {
        for (int j = 0, l = 0; j < col; j++, l++)
        {
            ans[l][k] = v[i][j];
        }
    }
    cout << "\n90 Rotated Matrix : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
void rotateMatrix2(vector<vector<int>> v)
{
    // Time : O(n^2)
    // Space : O(n^2)

    int row = v.size();
    int col = v[0].size();

    // take transpose of it first

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i < j)
            {
                swap(v[i][j], v[j][i]);
            }
        }
    }

    // now reverse each row to get the results

    int l;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0, l = col - 1; j < col / 2; j++, l--)
        {
            swap(v[i][j], v[i][l]);
        }
    }
    cout << "\n90 Rotated Matrix : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> v = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    rotateMatrix1(v);
    rotateMatrix2(v);
    return 0;
}