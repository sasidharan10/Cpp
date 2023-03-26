#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void printSubsetSum1(int index, vector<int> v, vector<int> &subsets, int sum)
{
    // Time  : O( (sum/v[index])^n )traversal
    // Space : O(n)    depth of tree

    if (index == v.size())
    {
        if (sum == 0)
        {
            for (auto i : subsets)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    if (v[index] <= sum)
    {
        sum -= v[index];
        subsets.push_back(v[index]);
        printSubsetSum1(index, v, subsets, sum);
        sum += v[index];
        subsets.pop_back();
    }
    printSubsetSum1(index + 1, v, subsets, sum);
}
void printSubsetSum2(int index, vector<int> v, vector<int> &subsets, int sum, int k)
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
    if (sum <= k)
    {
        sum += v[index];
        subsets.push_back(v[index]);
        printSubsetSum2(index, v, subsets, sum, k);
        sum -= v[index];
        subsets.pop_back();
    }
    printSubsetSum2(index + 1, v, subsets, sum, k);
}
int main()
{
    int k = 3;
    vector<int> v{1, 4, 2};
    vector<int> subsets;
    int sum = 0, index = 0;
    printSubsetSum1(index, v, subsets, k);
    cout << endl;
    subsets.clear();
    index = 0, sum = 0, k = 3;
    printSubsetSum2(index, v, subsets, sum, k);
    return 0;
}

// count the sum of subsets equal to 'k', the same number can be picked up many times.