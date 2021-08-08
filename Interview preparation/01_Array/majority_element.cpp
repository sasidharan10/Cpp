#include <iostream>
#include <algorithm>
using namespace std;
int findCandidate(int *a, int n)
{
    int major_index = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[major_index] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            major_index = i;
            count = 1;
        }
    }
    return a[major_index];
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
    if (count > n / 2)
    {
        cout << "Majority element : " << majority << endl;
        cout << "Occurence : " << count << endl;
    }
    else
        cout << "No Majority Element Found!!!" << endl;
}
int main()
{
    int a[] = {1, 3, 3, 1, 2};
    int n = (sizeof(a)) / sizeof(a[0]);
    printMajority(a, n);
    return 0;
}