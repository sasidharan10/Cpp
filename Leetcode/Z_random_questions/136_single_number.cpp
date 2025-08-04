#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int singleNumber2(vector<int> &nums)
{
    // TC: O(N)
    // SC: O(1)

    if (nums.size() == 1)
        return nums[0];
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        ans ^= nums[i];
    }
    return ans;
}
int singleNumber1(vector<int> &nums)
{
    // TC: O(NlogN)
    // SC: O(1)

    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i += 2)
    {
        if (nums[i] != nums[i - 1])
            return nums[i - 1];
    }
    return nums[nums.size() - 1];
}
int main()
{
    vector<int> nums{4, 1, 2, 1, 2};
    cout << "Single Number: " << singleNumber2(nums);
    return 0;
}

/*

According to this XOR gate, the output is true , only if both the inputs are of opposite kind .
That is ,
A B Y
0 0 0
0 1 1
1 0 1
1 1 0

We apply the extended version of this gate in our bitwise XOR operator.
If we do "a^b" , it means that we are applying the XOR gate on the 2 numbers in a bitwise fashion
( on each of the corresponding bits of the numbers).
Similarly , if we observe ,

A^A=0
A^B^A=B
(A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.
Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a

*/