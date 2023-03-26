#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
bool countDivision(int index, vector<int> v, vector<int>subset, int sum, int k)
{
    if(index==v.size())
    {
        if(sum%k==0 && sum!=0)
        {
            for (auto &&i : subset)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    sum+=v[index];
    subset.push_back(v[index]);
    if(countDivision(index+1, v, subset, sum,k))
        return true;
    sum-=v[index];
    subset.pop_back();
    if(countDivision(index+1, v, subset, sum,k))
        return true;
    return false;
}
int main()
{
    vector<int> v{1, 2, 3, 4};
    vector<int> subset;
    int k = 3;
    int sum=0;
    countDivision(0, v, subset, sum, k);
    return 0;
}