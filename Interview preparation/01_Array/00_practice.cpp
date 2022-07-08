#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
void rec(int n)
{
    if (n == 0)
        return;
    else
    {
        cout << "Sasi" << endl;
        // cout<<n<<endl;
        rec(n - 1);
    }
}
int main()
{
    // int n = 5;
    // rec(5);
    int a[] = {8, 2, 14, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int target=18;
    unordered_map<int,int>m;
    vector<int>v;
    for (int i = 0; i < n; i++)
    {
        if(m.find(target-a[i])!=m.end())
        {
            v.push_back(m[target-a[i]]);
            v.push_back(i);
            break;
        }
        else
            m[a[i]]=i;
    }
    for (auto i : v)
        cout<<i<<" : ";
    // cout<<v[0]<<" : "<<v[1]<<endl;
    return 0;
    
}