#include <iostream>
using namespace std;
void heapify(int *a, int i, int n)
{
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;
    if(left<n && a[left]<a[smallest])
        smallest=left;
    if (right<n && a[right]<a[smallest])
        smallest=right;
    if(smallest!=i)
    {
        swap(a[i],a[smallest]);
        heapify(a,smallest,n);
    }
}
void minHeap(int *a, int n)
{
    int start=(n/2)-1;  // internal nodes
    for (int i = start; i >= 0; i--)
    {
        heapify(a,i,n);
    }
    cout << "Min Heap : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}
int main()
{
    int a[] = {6, 5, 8, 4, 9, 7, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    minHeap(a, n);
    cout << "\nThe Sorted array is : ";
    for (int i : a)
        cout << i << " ";

    return 0;
}