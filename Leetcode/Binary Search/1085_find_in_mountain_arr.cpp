#include <bits/stdc++.h>
using namespace std;
class MountainArray
{
public:
    vector<int> arr;
    MountainArray()
    {
        arr = {1, 2, 3, 4, 5, 3, 1};
    }
    int get(int index)
    {
        return arr[index];
    }
    int length()
    {
        return arr.size();
    }
};
class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start) / 2;
        while (start < end)
        {
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                start = mid + 1;
            else
                end = mid - 1;
            mid = start + (end - start) / 2;
        }
        int peak = mid;
        int left = -1, right = -1;
        // left side array
        start = 0, end = peak;
        mid = start + (end - start) / 2;
        while (start < end)
        {
            int middle = mountainArr.get(mid);
            if (middle == target)
            {
                left = mid;
                break;
            }
            else if (target > middle)
                start = mid + 1;
            else
                end = mid - 1;
            mid = start + (end - start) / 2;
        }
        // right side array
        start = peak, end = n - 1;
        mid = start + (end - start) / 2;
        while (start < end)
        {
            int middle = mountainArr.get(mid);
            if (middle == target)
            {
                right = mid;
                break;
            }
            else if (target < middle)
                start = mid + 1;
            else
                end = mid - 1;
            mid = start + (end - start) / 2;
        }
        if (left == right)
            return left;
        else if (left != -1)
            return left;
        else
            return right;
    }
};
int main()
{
    Solution s;
    MountainArray mountainArr;
    vector<int> nums{1, 2, 3, 4, 5, 3, 1};
    int target = 3;
    cout << "Index of Target: " << s.findInMountainArray(target, mountainArr) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/