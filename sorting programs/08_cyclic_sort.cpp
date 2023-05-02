#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void cycleSort(int *a, int n)
{
    int min = *min_element(a, a + n);
    int i = 0;
    while (i < n)
    {
        if (a[i] != i + min)
            swap(a[i], a[a[i] - min]);
        else
            i++;
    }
}
int main()
{
    // int a[] = {3, 6, 4, 1, 2, 5};
    int a[] = {19, 17, 20, 15, 18, 16};
    int n = sizeof(a) / sizeof(a[0]);
    cycleSort(a, n);
    cout << "\nThe Sorted array is : ";
    for (int i : a)
        cout << i << " ";
    return 0;
}