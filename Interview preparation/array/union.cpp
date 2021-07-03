#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
void Union(int *a, int *b, int n1, int n2)
{
    set<int> inter;  // using set to eliminate duplicate values
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            inter.insert(a[i++]);
        if (a[i] > b[j])
            inter.insert(b[j++]);
        if (a[i] == b[j])
        {
            inter.insert(a[i]);
            i++;
            j++;
        }
    }
    // printing remaining elements
    while (i < n1)
    {
        inter.insert(a[i++]);
    }
    while (j < n2)
    {
        inter.insert(b[j++]);
    }

    cout << "Intersection is : ";
    for (int i : inter)
        cout << i << " ";
}
void Intersection(int *a,int *b,int n1,int n2)
{
    set<int> un;
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
            i++;
        if(a[i]>b[j])
            j++;
        if(a[i]==b[j])
        {
            un.insert(a[i]);
            i++;
            j++;
        }
    }
    cout << "\nUnion is : ";
    for (int i : un)
        cout << i << " ";
}
int main()
{
    int a[]{1, 2, 3, 3,3,3,5, 6,6,6,6, 8};
    int b[]{1,1,1,1, 3, 7,7,7,7, 8, 9};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    Union(a, b, n1, n2);
    Intersection(a,b,n1,n2);
    return 0;
}