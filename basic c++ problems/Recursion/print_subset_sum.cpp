#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void printSubsetSum(int index, vector<int> v, vector<int> &subsets, int sum, int k)
{
    if (index == v.size())
    {
        if (sum % k == 0 && subsets.size() != 0)
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
int countSubsetSum(int index, vector<int> v, int sum, int k)
{
    if (index == v.size())
    {
        if (sum % k == 0 && sum != 0)
            return 1;
        return 0;
    }
    sum += v[index];
    int left = countSubsetSum(index + 1, v, sum, k);
    sum -= v[index];
    int right = countSubsetSum(index + 1, v, sum, k);
    return left + right;
    // return countSubsetSum(index + 1, v, sum + v[index], k) + countSubsetSum(index + 1, v, sum, k);
}
int main()
{
    int k = 3;
    vector<int> v{4, 3, 2};
    vector<int> subsets;
    int sum = 0, index = 0;
    printSubsetSum(index, v, subsets, sum, k);
    cout << "Subset count: " << countSubsetSum(index, v, sum, k);
    return 0;
}