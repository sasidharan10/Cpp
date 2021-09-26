#include <iostream>
#include <algorithm>
using namespace std;
int findCandidate(int *a, int n)
{
    int candidate = a[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (candidate == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            candidate = a[i];
            count = 1;
        }
    }
    cout<<"\ncount : "<<candidate<<endl;
    return candidate;
}
void printMajority(int *a, int n)
{
    int count = 0;
    int majority = findCandidate(a, n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == majority)
            count++;
    }
    if (count >(n / 3))
    {
        cout << "Majority element : " << majority << endl;
        cout << "Occurence : " << count << endl;
    }
    else
        cout << "No Majority Element Found!!!" << endl;
}
int main()
{
    int a[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = (sizeof(a)) / sizeof(a[0]);
    printMajority(a, n);
    return 0;
}