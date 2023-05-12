#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
int main()
{
    vector<int> v;
    int i=3; int j=3;
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    a.push_back(1);
    b.push_back(1);
    b.push_back(1);
    int c=a.size();
    int d=b.size();
    int e=c-d;
    cout<<e<<endl;
    v.push_back(c-d);
    for (auto &&i : v)
    {
        cout<<i<<" ";
    }
    
    cout << endl;
    return 0;
}