#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int n = pref.size();
        for (int i = n - 1; i > 0; i--)
        {
            pref[i] = pref[i] ^ pref[i - 1];
        }
        return pref;
    }
};
int main()
{
    Solution s;
    vector<int> nums{5, 2, 0, 3, 1};
    vector<int> ans = s.findArray(nums);
    cout << "Original Array of Prefix Xor: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-original-array-of-prefix-xor

Youtube: https://www.youtube.com/watch?v=TDjmp768H3Q

algorithm:

- XOR = if 2 bits are same, XOR = 0
-       if 2 bits are different, XOR = 1
- A ^ B = B ^ A (commutative)
- A ^ (B ^ C)= (A ^ B) ^ C (associative)
- A ^ 0 = A
- A ^ A = 0 (both are same)

- Lets take pref XOR pref = {5, 2, 0, 3, 1}, and original arr = {a0, a1, a2, a3, a4}
- Now the prefix XOR can be written as
- 5 = a0
- 2 = a0 ^ a1
- 0 = a0 ^ a1 ^ a2
- 3 = a0 ^ a1 ^ a2 ^ a3
- 1 = a0 ^ a1 ^ a2 ^ a3 ^ a4

- Which implies a4 = (a0 ^ a1 ^ a2 ^ a3 ^ a4) ^ (a0 ^ a1 ^ a2 ^ a3) = 1 ^ 3 = 2
- The same values get eliminated by XOR property, 
- So we can just XOR the last 2 values, to get the last value, until we reach the second element.
- The first element is the same in both array.

*/

/*

2433. Find The Original Array of Prefix Xor

You are given an integer array pref of size n. Find and return 
the array arr of size n that satisfies:

pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
Note that ^ denotes the bitwise-xor operation.

It can be proven that the answer is unique.


Example 1:

Input: pref = [5,2,0,3,1]
Output: [5,7,2,3,2]
Explanation: From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.
Example 2:

Input: pref = [13]
Output: [13]
Explanation: We have pref[0] = arr[0] = 13.

*/