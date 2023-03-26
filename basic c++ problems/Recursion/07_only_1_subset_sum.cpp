#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool printOneSubsetSum(int index, vector<int> v, vector<int> &subsets, int sum, int k)
{
    if (index == v.size())
    {
        if (sum == k)
        {
            for (auto i : subsets)
                cout << i << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    sum += v[index];
    subsets.push_back(v[index]);
    if (printOneSubsetSum(index + 1, v, subsets, sum, k))
        return true;
    sum -= v[index];
    subsets.pop_back();
    if (printOneSubsetSum(index + 1, v, subsets, sum, k))
        return true;
    return false;
}
int main()
{
    int k = 3;
    vector<int> v{1, 2, 3};
    vector<int> subsets;
    int sum = 0, index = 0;
    printOneSubsetSum(index + 1, v, subsets, sum, k);
    return 0;
}

// print only 1 subsets which are divisible by k, each element can only be picked once.