#include<iostream>
#include<algorithm>
using namespace std;
int maxProduct1(int *a,int n)
{
    // Time : O(n^2)
    // Space : O(1)

    int result=a[0],prod=1;
    for (int i = 0; i < n; i++)
    {
        prod=a[i];
        for (int j =i+1; j < n; j++)
        {
            prod*=a[j];
        }
        result=max(result,prod);
    }
    return result;

}
int maxProduct2(int *a,int n)
{
    // Time : O(n)
    // Space : O(1)

    int max_overall=a[0];
    int max_end_here=a[0];
    int min_end_here=a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i]==0)
        {
            max_end_here=min_end_here=1;
        }
        int temp=max_end_here;  // we store max in temp because it will get updated in next step
        max_end_here=max({a[i],max_end_here*a[i],min_end_here*a[i]});
        min_end_here=min({a[i],temp*a[i],min_end_here*a[i]});
        max_overall=max(max_overall,max_end_here);
    }
    return max_overall;

}
int main()
{
    // int a[] = {6, -3, -10, 0, 2};
    int a[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<"Max Prod O(n^2) : "<<maxProduct1(a,n)<<endl;
    cout<<"Max Prod O(n)   : "<<maxProduct2(a,n)<<endl;
    return 0;
}