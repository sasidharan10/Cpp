#include <iostream>
#include <algorithm>
using namespace std;
int FindIndex(int *a, int left, int right)
{
    right = right - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        // mid==0 to chack if all elements are 1
        if ((mid == 0 || a[mid - 1] == 0) && a[mid] == 1)
            return mid;
        else if (a[mid] == 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int maxRow(int a[][4], int col, int row)
{
    int max = -1, index = 0, result = 0;
    for (int i = 0; i < row; i++)
    {
        index = FindIndex(a[i], 0, row);
        if (index != -1 && col - index > max)
        {
            max = col - index;
            result = i;
        }
    }
    return result;
}
int main()
{
    int mat[4][4] = {{0, 0, 0, 1},
                     {0, 1, 1, 1},
                     {1, 1, 1, 1},
                     {0, 0, 0, 0}};

    cout << "Index of row with maximum 1s is " << maxRow(mat, 4, 4);

    return 0;
}

/*

Find the row with maximum number of 1s
O(mlogn)

*/