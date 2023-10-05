#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // TC: O(2n)
        // SC: O(1)

        int el = 0, cnt = 0, n = nums.size();
        ;
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                cnt = 1;
                el = nums[i];
            }
            else if (nums[i] == el)
            {
                cnt++;
            }
            else
                cnt--;
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (el == nums[i])
            {
                cnt++;
                if (cnt > (n / 2))
                    return el;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    cout << "Majority element : " << s.majorityElement(nums) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

- Brute force: run 2 loops, find count of every element and return the result. - O(n^2)
- Using Hashmap: store frequency and then check for each element if > (n/2).

*/