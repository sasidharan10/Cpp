#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void printSorted(vector<vector<int>> v)
{
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            ans.push_back(v[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<"Sorted Array : ";
    for (int i : ans)
    {
        cout<<i<<" ";
    }
}
int main()
{
    vector<vector<int>> v= { {10, 20, 30, 40},
                            {15, 25, 35, 45},
                            {27, 29, 37, 48},
                            {32, 33, 39, 50},
                                };
  printSorted(v);
  return 0;
}