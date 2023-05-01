#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void findPermutation(vector<int> v, vector<int> &ds, vector<vector<int>> &ans, vector<bool> &freq)
{
    if (ds.size() == v.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (freq[i] == false)
        {
            freq[i] = true;
            ds.push_back(v[i]);
            findPermutation(v, ds, ans, freq);
            ds.pop_back();
            freq[i] = false;
        }
    }
}
void printPermutations(vector<int> v)
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<bool> freq(v.size(), false);
    findPermutation(v, ds, ans, freq);
    cout << "All permutations: " << endl;
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> v{1, 2, 3};
    printPermutations(v);
    return 0;
}