#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int countSubset(int index, vector<int> v, int sum)
{
    if(sum==0) 
        return 1;  // to 
    if (index == v.size())
    {
        if (sum == 0)
            return 1;
        return 0;
    }
    int left = 0;
    int right = 0;
    if (v[index] <= sum)
    {
        sum -= v[index];
        left = countSubset(index, v, sum);
        sum += v[index];
    }
    right = countSubset(index + 1, v, sum);
    return left + right;
}
int main()
{
    vector<int> v{1, 2, 3, 4};
    int sum = 3;
    cout << "Count of subsets: " << countSubset(0, v, sum);
    return 0;
}