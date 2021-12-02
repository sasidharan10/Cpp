#include<iostream>
#include<algorithm>
using namespace std;
int main()
{

    int a[]={3,3,3,3};
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;
    int count=0,sum=0;
    int l=0,j=0;
    for (int i = 0; i < n; i++)
    {
        l=k+i;
        for (int j = i; j < l; j++)
        {
            sum+=a[j];
        }
        
        l=0;
        if(sum%2==0)
            count++;
        sum=0;
    }
    if(count==0)
        count=-1;
    return count;
    cout<<"Count : "<<count<<endl;
    return 0;

}