#include <iostream>
void Merge(int *A, int *L, int leftCount, int *R, int rightCount)
{
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    while (i < leftCount && j < rightCount)
    {
        if (L[i] < R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while (i < leftCount)
        A[k++] = L[i++];
    while (j < rightCount)
        A[k++] = R[j++];
}

void MergeSort(int *A, int n)
{
    int mid, i, *L, *R;
    if (n < 2)
        return;

    mid = n / 2; // find the mid index.

    // L = (int *)malloc(mid * sizeof(int));
    // R = (int *)malloc((n - mid) * sizeof(int));
    L = new int[mid];
    R = new int[n-mid];

    for (i = 0; i < mid; i++)
        L[i] = A[i];
    for (i = mid; i < n; i++)
        R[i - mid] = A[i];

    MergeSort(L, mid);            // sorting the left subarray
    MergeSort(R, n - mid);        // sorting the right subarray
    Merge(A, L, mid, R, n - mid); // Merging L and R into A as sorted list.
    delete []L;
    delete []R;
}

int main()
{

    int A[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17};
    int i, numberOfElements;
    numberOfElements = sizeof(A) / sizeof(A[0]);
    MergeSort(A, numberOfElements);
    for (i = 0; i < numberOfElements; i++)
        printf("%d ", A[i]);
    return 0;
}