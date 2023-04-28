#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
    int j = n-1;
    int k = m + n - 1;
    while (i>=0 && j>=0)
    {
        if(nums1[i]>=nums2[j])
            nums1[k--]=nums1[i--];
        else
            nums1[k--]=nums2[j--];
    }
    while (i>=0)
    {
        nums1[k--]=nums1[i--];
    }
    while (j>=0)
    {
        nums1[k--]=nums2[j--];
    }
    }
};
int main()
{
    Solution s;
    int m = 3, n = 3;
    vector<int>nums1{1,2,3,0,0,0};
    vector<int>nums2{2,5,6};
    s.merge(nums1,m,nums2,n);
    for (auto &&i : nums1)
    {
        cout<<i<<" ";    
    }
    return 0;
}


/*

link: 

leetcode: https://leetcode.com/problems/merge-sorted-array/description/

*/