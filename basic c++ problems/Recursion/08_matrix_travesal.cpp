#include <iostream>
#include <vector>
#include <string>
using namespace std;
// consider its a 2D 3*2 matrix
int row = 3;
int col = 2;
void matrixPath(int i, int j, string str, vector<string> &ans)
{
    if (i == row - 1 && j == col - 1)
    {
        ans.push_back(str);
        return;
    }
    if (i >= row || j >= col)
        return;
    // down path
    str.append("R");
    matrixPath(i, j + 1, str, ans);
    str.pop_back();

    // right path
    str.append("D");
    matrixPath(i + 1, j, str, ans);
    str.pop_back();

    return;
}
int main()
{
    string str = "";
    vector<string> ans;
    matrixPath(0, 0, str, ans);
    cout << "Possible paths to reach the end: " << endl;
    for (auto &&i : ans)
    {
        cout << i << endl;
    }
    return 0;
}