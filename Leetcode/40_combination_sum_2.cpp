#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void findCombination(int index, vector<int> v, vector<int> &temp, vector<vector<int>> &ans, int target)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = index; i < v.size(); i++)
    {
        if (i > index && v[i] == v[i - 1]) // refer below
            continue;
        if (v[i] > target)
            break;
        temp.push_back(v[i]);
        findCombination(i + 1, v, temp, ans, target - v[i]);
        temp.pop_back();
    }
}
void calCombination(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    findCombination(0, candidates, temp, ans, target);
    cout << "Combinations: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    calCombination(candidates, target);
    return 0;
}

/*

link: https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=12

i>index (or i!=index) is used, so that we can pick the element first time without
    checking  this condition "v[i] == v[i - 1]".
    eg: [1,1,1,2,2]
    as we go down the recursion call, we pick each one position till n-1.
    suppose I picked 1 from 0th index and now i am picking elements for 1st index,
    so in that case, i should not check my 1st index element with 0th index, as it was lready picked,
    but due to this condition "v[i] == v[i - 1]", it will check and we might skip that element.
    so we use "i>index (or i!=index)" to skip that condition for first time.

*/