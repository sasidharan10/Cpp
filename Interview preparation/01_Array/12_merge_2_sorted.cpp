#include <iostream>
#include <algorithm>
using namespace std;
void mergeArray1(int *a, int n, int *b, int m)
{
    // O(m*n)

    //first loop is for the smaller array where we will store all greater elements
    for (int i = m - 1; i >= 0; i--)
    {
        int j;
        int last = a[n - 1]; // last element
        // this loop will compare a with b and create a hole in a to store the smaller element from
        // b to a in its approprite position
        for (j = n - 2; j >= 0 && a[j] > b[i]; j--)
        {
            a[j + 1] = a[j];
        }
        /*
        - (j!=n-2) means b[i] is greatest element and no need to change it.
        - last > b[i] to check if last element is greater than a[i] since in first loop
          last is not compared with b[i]    
        - we j!=n-2 to check if any swaps have happened
        */
        if (j != n - 2 || last > b[i])
        {
            a[j + 1] = b[i];
            b[i] = last;
        }
    }
}
void mergeArray2(int *a, int n, int *b, int m)
{
    // O(n) + O(m) + O(nlogm)+ O(mlogn)

    int i = 0;              // for a1
    int j = 0;              // for a2
    int k = n - 1;  // iterator for last in a1 to swap it with a2 (swapping all largest element to a2)
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

/*

link: https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/

leetcode: 

*/