#include <iostream>
#include <vector>
#include <string>
using namespace std;
// consider its a 2D 3*2 matrix, we can only in 2 directions, i.e., "right" and "down"
int row = 3;
int col = 2;
void matrixPath1(int i, int j, string str, vector<string> &ans)
{
    // Time  : O(2^(row*col))
    // Space : O(n*m)    depth of tree

    if (i == row - 1 && j == col - 1) // end matrix
    {
        ans.push_back(str);
        return;
    }
    if (i >= row || j >= col) // boundary case
        return;
    // down path
    str.push_back('R');
    matrixPath1(i, j + 1, str, ans);
    str.pop_back();

    // right path
    str.push_back('D');
    matrixPath1(i + 1, j, str, ans);
    str.pop_back();

    return;
}
void matrixPath2(int i, int j, string str, vector<string> &ans, vector<vector<int>> &hash)
{
    if (i == row - 1 && j == col - 1)
    {
        ans.push_back(str);
        return;
    }
    if (i >= row || i < 0 || j >= col || j < 0 || hash[i][j] == 1)
        return;

    hash[i][j] = 1; // marking it as visited

    // right
    str.push_back('R');
    matrixPath2(i, j + 1, str, ans, hash);
    str.pop_back();

    // down
    str.push_back('D');
    matrixPath2(i + 1, j, str, ans, hash);
    str.pop_back();

    // left
    str.push_back('L');
    matrixPath2(i, j - 1, str, ans, hash);
    str.pop_back();

    // up
    str.push_back('U');
    matrixPath2(i - 1, j, str, ans, hash);
    str.pop_back();

    hash[i][j] = 0; // since traversal is done, we have to umark it
}
int main()
{
    string str = "";
    vector<string> ans;
    vector<vector<int>> v(col + 1, vector<int>(row + 1, 0));
    matrixPath1(0, 0, str, ans);
    cout << "Possible paths to reach the end: " << endl;
    for (auto &&i : ans)
    {
        cout << i << endl;
    }

    ans.clear();

    matrixPath2(0, 0, str, ans, v);
    cout << "Possible paths to reach the end: " << endl;
    for (auto &&i : ans)
    {
        cout << i << endl;
    }

    return 0;
}