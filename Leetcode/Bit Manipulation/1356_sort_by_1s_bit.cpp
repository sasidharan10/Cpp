#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // getting count of number of 1'1s
    static int bitCount(int num)
    {
        
        int cnt = 0;
        while (num > 0)
        {
            cnt += num & 1;
            num >>= 1;
        }
        return cnt;
    }
    static bool cmp(int &a, int &b)
    {
        // TC: O(nlogn) *O(log2(num))
        // SC: O(1)

        int cntA = bitCount(a);
        int cntB = bitCount(b);
        if (cntA == cntB)
            return a < b;
        else
            return cntA < cntB;
    }
    static bool cmp2(int &a, int &b)
    {
        // TC: O(nlogn)
        // SC: O(1)

        // gets 1s bit count in O(1) TC
        int cntA = __builtin_popcount(a);
        int cntB = __builtin_popcount(b);
        if (cntA == cntB)
            return a < b;
        else
            return cntA < cntB;
    }
    vector<int> sortByBits(vector<int> &arr)
    {

        // sort(arr.begin(), arr.end(), cmp);
        sort(arr.begin(), arr.end(), cmp2);
        return arr;
    }
};
int main()
{
    Solution s;
    vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ans = s.sortByBits(nums);
    cout << "Array after sorting by 1s bit: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

Youtube: https://www.youtube.com/watch?v=2owpaafBIgw

algorithm:

- We modify the sort algorithm, to sort it by the count of number of '1's
- then we return bbased on the value.
- We can also use __buitlin_popcount(A), which will return count of no of '1' bits
  in A, which is more faster than our custom function.

*/

/*

1356. Sort Integers by The Number of 1 Bits

You are given an integer array arr. Sort the integers in the array in ascending order 
by the number of 1's in their binary representation and in case of two or more integers 
have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them 
in ascending order.

*/