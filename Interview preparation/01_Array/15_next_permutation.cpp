#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
void nextPermutation1(int *a, int n)
{
    // using library function

    next_permutation(a, a + n);
}
void findPermutation(vector<int> v, vector<int> &ds, set<vector<int>> &ans, vector<bool> &freq)
{
    if (ds.size() == v.size())
    {
        ans.insert(ds);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (freq[i] == false)
        {
            freq[i] = true;
            ds.push_back(v[i]);
            findPermutation(v, ds, ans, freq);
            ds.pop_back();
            freq[i] = false;
        }
    }
}
void nextPermutation3(int *a, int n)
{
    
    // TC: O(n!*n)  brute force
    // SC: O(n)
    
    vector<int> v;
    v.assign(a, a + n);
    set<vector<int>> ans;
    vector<int> ds;
    vector<bool> freq(n, false);
    findPermutation(v, ds, ans, freq);
    // cout << "All permutations: "<<endl;
    // for (auto &&i : ans)
    // {
    //     for (auto &&j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    set<vector<int>>::iterator it;
    // v.clear();
    // v={3,1,2};
    it = ans.find(v);
    ++it; // next permutation
    cout << "Next Permutation is : ";
    for (auto &&i : *it)
    {
        cout << i << " ";
    }
}
void nextPermutation2(int *a, int n)
{
    // TC: O(nlogn) optimised
    // SC: O(1)

    // finding peak element which is as right as possible
    if (n <= 1)
        return;
    int peak = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            peak = i;
    }
    // case 1 :
    // if no peak exist, that means the array is sorted in desc order. we have to sort it in asc order
    if (peak == -1)
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(a[i], a[n - i - 1]);
        }
        return;
    }
    // case 2 :
    int index = peak;
    for (int i = peak; i < n; i++)
    {
        if (a[i] > a[peak - 1] && a[i] < a[index])
        {
            index = i;
        }
    }
    // now index contains the peak element which is to be swapped
    swap(a[peak - 1], a[index]);
    // now sort reaming elements from the peak element to last of array
    sort(a + peak, a + n);
}
int main()
{
    // int a[]{1, 2, 3, 5, 4, 2};
    int a[]{1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    nextPermutation1(a, n);
    cout << "Next Permutation is : ";
    for (int i : a)
    {
        cout << i << " ";
    }
    return 0;
}

/*

Problem :
- The array is a representation of a number with the weightage [...,1000,100,10,1](hundreds,tens,ones etc).
- The problem is to find next bigger number closest to given number by rearraing order of the array.

Examples :
1) [1,2,4,1] = [1,4,1,2]  // swapping peak(4) with its left adjacent and sorting remaining right elements
2) [1,2,4,3] = [1,3,2,4]
3) [4,3,2,1] = [1,2,3,4]  // this ex does not have next permutation, so we just sort it in desc order
4) [1,2,3,4] = [1,2,4,3]

Solution :
- We can find the element having highest peak value from right(So they will have less weightage) and
  swapping it with adjacent left value to get next big value.
- We also have to sort the remaining elements from that peak value to right, if any exist.

Special cases :

- If the array is in decending order, we cannot find next highest combination, so we have sort it
  in ascending order.
- [1,2,3,5,4,2] In this array, peak is 5,but we cannot swap it with left element as to the right,
  as we have 4 which is closest to 5 so we have to swap 5 with 4 to make next permutation = [1,2,4,2,3,5].
  This is a special case.

*/