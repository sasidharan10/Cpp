#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
// kadane Algorithm
void maxSubArraySum(int *a, int n)
{
    // O(n)

    int max_end_here = 0;
    int max_so_far = INT_MIN;
    int start = 0, end = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        max_end_here += a[i];
        if (max_end_here > max_so_far)
        {
            max_so_far = max_end_here;
            start = s;
            end = i;
        }
        if (max_end_here < 0)
        {
            max_end_here = 0;
            s = i + 1;
        }
    }
    cout << "Max Sum of Sub-Array is (kadane algorithm) : " << max_so_far << endl;
    cout << "Sub-Array is : ";
    for (int i = start; i <= end; i++)
    {
        cout << a[i] << " ";
    }
}

// dp programming

void maxSubArraySum2(int a[], int size)
{
    int max_so_far = a[0];
    int curr_max = a[0];

    for (int i = 1; i < size; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    cout << "\nMax Sum of Sub-Array is (dp) : " << max_so_far << endl;
}
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    maxSubArraySum(a, n);
    maxSubArraySum2(a, n);
    return 0;
}

/*

Largest Sum Contiguous Subarray

*/