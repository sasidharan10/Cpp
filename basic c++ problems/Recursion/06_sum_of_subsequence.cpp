#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void findSumSubsequence(int index, vector<int> v, vector<int> &ans, int sum)
{
    if (index == v.size())
    {
        ans.push_back(sum);
        return;
    }
    findSumSubsequence(index + 1, v, ans, sum + v[index]);
    findSumSubsequence(index + 1, v, ans, sum);
}
int main()
{
    // vector<int>v{2,3};
    vector<int> v{5, 2, 1};
    vector<int> ans;
    int sum = 0;
    findSumSubsequence(0, v, ans, sum);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

// print sum of each subsets