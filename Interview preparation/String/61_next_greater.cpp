#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void nextGreatest(vector<int>v)
{
    int n=v.size();
    if(n<=1)
        return;
    int peak=-1;
    for (int i = 1; i < n; i++)
    {
        if(v[i-1]<v[i])
            peak=i;
    }
    if(peak==-1)
        cout<<"NOT POSSIBLE"<<endl;
    int index=peak;
    for (int i = peak; i < n; i++)
    {
        if(v[i]<v[peak] && v[i]>v[peak-1])
            index=i;
    }
    swap(v[peak-1],v[index]);
    sort(v.begin()+peak,v.end());
    cout<<"Next Greatest : ";
    for (int i : v)
    {
        cout<<i<<" ";  
    }
}
int main()
{
    vector<int> v{ 5,3,4,9,7,6 };
    nextGreatest(v);
    return 0;
}