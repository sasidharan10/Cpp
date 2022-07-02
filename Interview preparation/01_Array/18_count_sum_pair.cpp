#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int sumPair1(int *a, int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == k)
            {
                count++;
            }
        }
    }
    return count;
}
int sumPair2(int *a, int n, int k)
{
    unordered_map<int,int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int x=k-a[i];
        if(m[x]==0)
        {
            m[a[i]]++;
        }
        else
        {
            count+=m[x];
            m[a[i]]++;
        }
    }
    cout<<endl;
    for(auto i:m)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }
    return count;
}
int main()
{
    int a[] = {1, 5, 7, -1};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 6;
    cout << "No of Pairs : " << sumPair1(a, n, k) << endl;
    cout << "No of Pairs : " << sumPair2(a, n, k) << endl;
    return 0;
}