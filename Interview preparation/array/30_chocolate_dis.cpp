#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int findMinDiff(int *a, int n, int m)
{
    if (m == 0 || n == 0)
        return 0;
    sort(a,a+n);
    int min = INT_MAX;
    for (int i = 0; i  <= (n-m); i++)
    {
        int dif = a[i + m - 1] - a[i];
        if (dif < min)
            min = dif;
    }
    return min;
}
int main()
{
    int a[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7; // Number of students
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Minimum difference is " << findMinDiff(a, n, m) << endl;
    return 0;
}