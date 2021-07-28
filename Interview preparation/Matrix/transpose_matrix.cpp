#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void transposeMatrix(vector<vector<int>> v)
{
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
    cout << "\nTranspose Matrix : " << endl;
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

    cout << "\nGiven Matrix : " << endl;
    int row = v.size();
    int col = v[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    transposeMatrix(v);
    return 0;
}

/*

Changing the rows of a matrix to column is known as transpose of a matrix

*/