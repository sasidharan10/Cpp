#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int countSubsetSumDiv(int index, vector<int> v, int sum, int k)
{
    if (index == v.size())
    {
        if (sum % k == 0 && sum != 0)
            return 1;
        return 0;
    }
    sum += v[index];
    int left = countSubsetSumDiv(index + 1, v, sum, k);
    sum -= v[index];
    int right = countSubsetSumDiv(index + 1, v, sum, k);
    return left + right;
    // return countSubsetSumDiv(index + 1, v, sum + v[index], k) + countSubsetDiv(index + 1, v, sum, k);
}
int main()
{
    int k = 3;
    vector<int> v{4, 3, 2};
    vector<int> subsets;
    int sum = 0, index = 0;
    cout << "Subset count: " << countSubsetSumDiv(index, v, sum, k);
    return 0;
}