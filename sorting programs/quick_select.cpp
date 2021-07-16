#include <iostream>
#include <algorithm>
using namespace std;
int partition(int *a, int start, int end)
{
    int pivot = a[end];
    int p_index = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[p_index]);
            p_index++;
        }
    }
    swap(a[p_index], a[end]);
    return p_index;
}
int quickSelect(int *a, int start, int end, int k)
{
    if (start <= end)
    {
        int p_index = partition(a, start, end);
        if (p_index == k - 1)
            return a[p_index];
        else if (p_index > k - 1)
            return quickSelect(a, start, p_index - 1, k);
        else if (p_index < k - 1)
            return quickSelect(a, p_index + 1, end, k);
    }
    return -1;
}
int main()
{
    int a[] = {6, 5, 8, 4, 7, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    int ans = quickSelect(a, 0, n - 1, k);
    cout << k << "th smallest element is : " << ans;
    return 0;
}