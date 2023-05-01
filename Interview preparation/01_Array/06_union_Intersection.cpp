#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <unordered_set>
using namespace std;
void Union(int *a, int *b, int n1, int n2)
{
    // TC: O(m+n) 1 traversal
    // SC: O(n) or O(1) if directly printing 

    vector<int> un; // using set can eliminate duplicate values
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            un.push_back(a[i++]);
        if (a[i] > b[j])
            un.push_back(b[j++]);
        if (a[i] == b[j])
        {
            un.push_back(a[i]);
            i++;
            j++;
        }
    }
    // printing remaining elements
    while (i < n1)
    {
        un.push_back(a[i++]);
    }
    while (j < n2)
    {
        un.push_back(b[j++]);
    }
    un.erase(unique(un.begin(), un.end()), un.end()); // erasing duplicate elements
    cout << "Union (without set) : ";
    for (int i : un)
        cout << i << " ";
}

void Intersection1(int *a, int *b, int n1, int n2)
{
    // TC: O(m+n) 1 traversal
    // SC: O(n) or O(1) if directly printing

    unordered_set<int> inter;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            i++;
        if (a[i] > b[j])
            j++;
        if (a[i] == b[j])
        {
            inter.insert(a[i]);
            i++;
            j++;
        }
    }
    cout << "\nIntersection (with set) : ";
    for (int i : inter)
        cout << i << " ";
}

void Intersection2(int *a, int *b, int n1, int n2)
{
    vector<int> v;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            i++;
        if (a[i] > b[j])
            j++;

        if (a[i] == b[j])
        {
            v.push_back(a[i]);
            i++;
            j++;
        }
    }
    v.erase(unique(v.begin(), v.end()), v.end()); // erasing duplicate elements
    cout << "\nIntersection (without set) : ";
    for (int i : v)
        cout << i << " ";
}
int main()
{
    int a[]{1, 1, 1, 2, 3, 3, 3, 5, 6, 6, 6, 6, 8};
    int b[]{1, 1, 1, 1, 3, 3, 3, 7, 7, 7, 7, 8, 9};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    Union(a, b, n1, n2);
    Intersection1(a, b, n1, n2);
    Intersection2(a, b, n1, n2);
    return 0;
}

/*

leetcode: 

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i=0;
    int j=0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
            i++;
        else if (nums1[i] > nums2[j])
            j++;
        else if (nums1[i] == nums2[j])
        {
            ans.insert(nums1[i]);
            i++;
            j++;
        }
    }
    vector<int>v(ans.begin(),ans.end());
    // vector<int>v;
    // for(auto i:ans)
    //     v.push_back(i);
    return v;
    }
};

*/