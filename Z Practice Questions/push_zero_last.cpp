#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> a={1,2,6,9,0,0,8,5,4,0,7,0,3,0};
    cout<<"Array is : ";
    for(int i:a)
        cout<<i<<", ";
    int n = sizeof(a) / sizeof(a[0]);
    sort(a.begin(),a.end());
    for (int i = 0; i < n; i++)
    {
        if(a[i]==0)
        {
            a.push_back(a[i]);
            a.erase(a.begin());
            i--;
        }
    }
    cout<<"\nAfter sorting : ";
    for(int i:a)
        cout<<i<<", ";
    return 0;
}