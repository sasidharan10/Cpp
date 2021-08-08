#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int findMedian1(int *a,int *b,int n,int m)
{
    // Time : O(n)
    // Space : O(n)

    int size=n+m;
    vector<int> v;
    int i=0,j=0;
    while (i<n && j<m)
    {
        if(a[i]<b[j])
        {
            v.push_back(a[i++]);
        }
        else if(b[j]<a[i])
        {
            v.push_back(b[j++]);
        }
        else
        {
            v.push_back(a[i++]);
            v.push_back(b[j++]);
        }
    }
    if(size%2==0)
        return (v[size/2]+v[(size/2)-1])/2;
    else
        return (v[size/2]);
}
int main()
{
    int a[] = {1, 12, 15, 26, 38};
    int b[] = {2, 13, 17, 30, 45};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    cout << "Median is " << findMedian1(a, b, n1,n2) << endl;
    // cout << "Median is " << findMedian2(a, b, n1) << endl;
    // cout << "Median is " << findMedian3(a, b, n1) << endl;
    return 0;
}
    