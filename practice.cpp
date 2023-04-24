#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>&a, int start, int end)
{
    int p_index = start;
    int pivot = a[end];
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[p_index]);
            p_index++;
        }
    }
    swap(a[end], a[p_index]);
    return p_index;
}
int quickSelect(vector<int>&a, int start, int end, int k)
{
    int p_index = partition(a, start, end);
    if (start <= end)
    {
        if (p_index == k - 1)
            return a[p_index];
        if (k - 1 > p_index)
            p_index = quickSelect(a, p_index + 1, end, k);
        else
            p_index = quickSelect(a, start, p_index - 1, k);
    }
    return a[p_index];
}
int main()
{
    vector<int>a{6, 5, 8, 4, 9, 7, 1, 3, 2};
    int n=a.size();
    // int a[] = {6, 5, 8, 4, 9, 7, 2, 3, 1};
    // int n = sizeof(a) / sizeof(a[0]);
    int k = 2;
    cout << "Kth element: " << quickSelect(a, 0, n - 1, k);
    cout << "\nThe Sorted array is : ";
    for (int i : a)
        cout << i << " ";

    return 0;
}


/*

class Solution {
public:
    int Partition(vector<int>& nums, int start, int end)
{
    int p_index = start;
    int pivot = nums[end];
    for (int i = start; i < end; i++)
    {
        if (nums[i] <= pivot)
        {
            swap(nums[i], nums[p_index]);
            p_index++;
        }
    }
    swap(nums[end], nums[p_index]);
    return p_index;
}
int quickSelect(vector<int>& nums, int start, int end, int k)
{
    
    if (start <= end)
    {
        int p_index = Partition(nums, start, end);
        if (p_index == k - 1)
            return nums[p_index];
        if (p_index > k - 1)
            p_index = quickSelect(nums, start, p_index - 1, k);
        else
            p_index = quickSelect(nums, p_index + 1, end, k);
    }
    return -1;
}
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return quickSelect(nums, 0, n-1, k);
    }
};

*/