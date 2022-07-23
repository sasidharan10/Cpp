#include <iostream>
#include <vector>
using namespace std;
void findSubsequence(int index, vector<int> v, vector<int> temp, vector<vector<int>> &ans)
{
    if (index == v.size())
    {
        if(temp.empty())
            temp.push_back(0);
        ans.push_back(temp);
        return;
    }
    temp.push_back(v[index]);
    findSubsequence(index + 1, v, temp, ans);
    temp.pop_back();
    findSubsequence(index + 1, v, temp, ans);
}
int main()
{
    vector<int> v{1, 2, 3};
    vector<int> temp;
    vector<vector<int>> ans;
    int index = 0;
    findSubsequence(index, v, temp, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}