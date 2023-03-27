#include <iostream>
#include <vector>
#include <string>
using namespace std;
int row = 2;
int col = 2;
void matrixPath1(int i, int j, string str, vector<string> &ans, vector<vector<int>> &hash)
{
    if (i == row - 1 && j == col - 1)
    {
        ans.push_back(str);
        return;
    }
    if (i >= row || i < 0 || j >= col || j < 0 || hash[i][j] == 1)
        return;

    hash[i][j] = 1; // marking it as visited

    string dir = "RDLU";
    int di[]{0, 1, 0, -1};
    int dj[]{1, 0, -1, 0};

    for (int x = 0; x < 4; x++)
    {
        str.push_back(dir[x]);
        matrixPath1(i + di[x], j + dj[x], str, ans, hash);
        str.pop_back();
    }

    hash[i][j] = 0; // since traversal is done, we have to umark it
}
void matrixPath2(int i, int j, string str, vector<string> &ans, vector<vector<int>> &hash)
{
    if (i >= row || i < 0 || j >= col || j < 0 || hash[i][j] == 1)
        return;
    if (i == row - 1 && j == col - 1)
    {
        ans.push_back(str);
        return;
    }
    hash[i][j] = 1;

    string dir[] = {"RR-", "RD-", "DD-", "LD-", "LL-", "LU-", "UU-", "RU-"};
    int di[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};

    for (int x = 0; x < 8; x++)
    {
        str.append(dir[x]);
        matrixPath2(i + di[x], j + dj[x], str, ans, hash);
        str.erase(str.end() - 3, str.end());
    }
    hash[i][j] = 0;
}

int countPath(int i, int j, vector<vector<int>>&hash)
{
    if(i>=row || i<0 || j>=col || j<0 || hash[i][j]==1)
        return 0;
    if(i==row-1 && j==col-1)
        return 1;
    int count=0;
    hash[i][j]=1;

    int di[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};

    for (int x = 0; x < 8; x++)
    {
        count+=countPath(i+di[x],j+dj[x], hash);
    }
    hash[i][j]=0;
    return count;
}

int main()
{
    vector<string> ans;
    vector<vector<int>> v(col + 1, vector<int>(row + 1, 0));
    matrixPath1(0, 0, "", ans, v);
    cout << "\nPossible paths to reach the end: " << endl;
    for (auto &&i : ans)
    {
        cout << i << endl;
    }

    ans.clear();

    matrixPath2(0, 0, "", ans, v);
    cout << "\nPossible paths to reach the end: " << endl;
    for (auto &&i : ans)
    { 
        cout << i << endl;
    }

    cout<<"\nCount of all possible path: "<<countPath(0,0,v);
    return 0;
}



/*

matrixPath1():
- consider its a 2D 2*2 matrix, we can traverse in all 4 directions, 
  find all the possible paths

matrixPath2():
- consider its a 2D 2*2 matrix, we can traverse in all 8 directions, 
  find all the possible paths

countPath():
- consider its a 2D 2*2 matrix, we can traverse in all 8 directions, 
  find total count of the possible paths
*/