#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maxWater1(int *a, int n)
{
    // Time : O(n^2)
    // Space : O(n)

    if (n <= 2)
        return 0;
    int trappedWater = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int leftmax = a[i];
        for (int j = 0; j < i; j++)
        {
            leftmax = max(leftmax, a[j]);
        }
        int rightmax = a[i];
        for (int k = i + 1; k < n; k++)
        {
            rightmax = max(rightmax, a[k]);
        }
        trappedWater += min(leftmax, rightmax) - a[i];
    }
    return trappedWater;
}
int maxWater2(int *a, int n)
{
    // Time : O(n)+O(n)+O(n)
    // Space : O(2n)

    if (n <= 2) // water will overflow if it has only 2 structure
        return 0;
    vector<int> left(n), right(n); // to store left prefix sum and right suffix sum
    int leftmax = a[0];
    left[0] = 0; // left max of first element will be 0 as it has no left structure
    for (int i = 1; i < n; i++)
    {
        left[i] = leftmax;
        leftmax = max(leftmax, a[i]);
    }
    int rightmax = a[n - 1];
    right[n - 1] = 0; // right max of last element will be 0 as it has no right structure
    for (int j = n - 2; j >= 0; j--)
    {
        right[j] = rightmax;
        rightmax = max(rightmax, a[j]);
    }
    int trappedWater = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] < left[i] && a[i] < right[i])
        {
            trappedWater += (min(left[i], right[i]) - a[i]);
        }
    }
    return trappedWater;
}
int maxWater3(int *a, int n)
{
    // Time : O(n)
    // Space : O(1)

    if (n <= 2)
        return 0;
    int leftmax = a[0];
    int rightmax = a[n - 1];
    int left = 1;
    int right = n - 2;
    int trappedWater = 0;
    while (left <= right)
    {
        if (leftmax < rightmax) //if min-height is leftmax
        {
            if (a[left] > leftmax) //if current element is greater
                leftmax = a[left];
            else
                trappedWater += leftmax - a[left];
            left++;
        }
        else
        {
            if (a[right] > rightmax) //if min-height is rightmax
                rightmax = a[right];
            else
                trappedWater += rightmax - a[right];
            right--;
        }
    }
    return trappedWater;
}
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Trapped water : " << maxWater1(arr, n) << endl;
    cout << "Trapped water : " << maxWater2(arr, n) << endl;
    cout << "Trapped water : " << maxWater3(arr, n) << endl;
    return 0;
}

/*

- the Algorithm here is to find the water level of each structure and subtract it
  with the height of the structure (min(left[i],right[i])-a[i]);
- In first solution, we store all rightmax and leftmax of all the element
  in a array and then compare it with the current element
- In 2nd solution, we traverse the array only once, keeping the current left,current
  right element as max and update it if the current is bigger.
*/