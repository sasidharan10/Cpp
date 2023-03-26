#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void printSubsetSum(int index, vector<int> v, vector<int> &subsets, int sum, int k)
{
    if (index == v.size())
    {
        if (sum == k)
        {
            for (auto i : subsets)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    sum += v[index];
    subsets.push_back(v[index]);
    printSubsetSum(index + 1, v, subsets, sum, k);
    sum -= v[index];
    subsets.pop_back();
    printSubsetSum(index + 1, v, subsets, sum, k);
}
int main()
{
    int k = 3;
    vector<int> v{1, 4, 2, 3};
    vector<int> subsets;
    int sum = 0, index = 0;
    printSubsetSum(index, v, subsets, sum, k);
    return 0;
}