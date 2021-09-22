#include<iostream>
#include<algorithm>
#include<iterator>
#include<unordered_map>
#include <cmath>
using namespace std;
// it can have more than 2 duplicate values
void duplicate1(int *a,int n)
{
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    unordered_map<int,int>::iterator itr;
    cout<<"The map is : "<<endl;
    for ( itr = m.begin(); itr != m.end(); itr++)
    {
        cout<<itr->first<<" : "<<itr->second<<" "<<endl;
    }
    cout<<"\nDuplicate1 values are : ";

    for ( itr = m.begin(); itr != m.end(); itr++)
    {
        if(itr->second>1)
            cout<<itr->first<<" ";
    }
}
void duplicate2(int *a,int n)
{
    cout<<"\nDuplicate2 values are : ";
    for (int i = 0; i < n; i++)
    {
        if(a[abs(a[i])]>=0)
            a[abs(a[i])]=-a[abs(a[i])];
        else
            cout<<abs(a[i])<<" ";
    }
    
    cout<<"\nThe array is : ";
    for (int j = 0; j < n; j++)
    {
        cout<<a[j]<<" ";
    } 
}
int main()
{
    int a[] = {6,  1, 1, 6, 4, 7, 10,2, 2, 4, 5, 5, };
    int n = sizeof(a) / sizeof(a[0]);
    duplicate1(a,n);
    duplicate2(a,n);
    return 0;
}