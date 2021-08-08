#include <iostream>
#include <algorithm>
using namespace std;
void mergeArray1(int *a1, int n, int *a2, int m)
{
    // O(m*n)

    //first loop is for the smaller array where we will store all greater elements
    for (int i = m - 1; i >= 0; i--)
    {
        int j;
        int last = a1[n - 1]; // last element
        // this loop will compare a1 with a2 and create a hole in a1 to store the smaller element from
        // a2 to a1 in its approprite position
        for (j = n - 2; j >= 0 && a1[j] > a2[i]; j--)
        {
            a1[j + 1] = a1[j];
        }
        /*
        - (j!=n-2) means a2[i] is greatest element and no need to change it.
        - last > a2[i] to check if last element is greater than a[i] since in first loop
          last is not compared with a[i]    
        */
        if (j != n - 2 || last > a2[i])
        {
            a1[j + 1] = a2[i];
            a2[i] = last;
        }
    }
}
void mergeArray2(int *a, int n, int *b, int m)
{
    // O(nlogm)+ O(mlogn)

    int i = 0;              // for a1
    int j = 0;              // for a2
    int k = n - 1;          // for iterator from last in a1 to swap it with a2 (swapping all largest element to a2)
    while (i <= k && j < m) // when k meets i it means all large elements are swapped to a2
    {
        if (a[i] < b[j])
            i++;
        else
        {
            swap(b[j++], a[k--]);
        }
    }
    // now sorting both array
    sort(a, a + n);
    sort(b, b + m);
}
int main()
{
    int a1[] = {2, 3, 5, 6, 8};
    int b1[] = {1, 4, 7, 9};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int m1 = sizeof(b1) / sizeof(b1[0]);
    mergeArray1(a1, n1, b1, m1);
    cout << "Sorted Array O(m*n): ";
    for (int i = 0; i < n1; i++)
    {
        cout << a1[i] << " ";
    }
    for (int j = 0; j < m1; j++)
    {
        cout << b1[j] << " ";
    }

    // 2nd method

    int a2[] = {2, 3, 5, 6, 8};
    int b2[] = {1, 4, 7, 9};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    int m2 = sizeof(b2) / sizeof(b2[0]);
    mergeArray2(a2, n2, b2, m2);
    cout << "\nSorted Array (o(nlogm)+ O(mlogn)) : ";
    for (int i = 0; i < n2; i++)
    {
        cout << a2[i] << " ";
    }
    for (int j = 0; j < m2; j++)
    {
        cout << b2[j] << " ";
    }
    return 0;
}