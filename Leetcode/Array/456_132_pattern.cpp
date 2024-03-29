#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        stack<int> st;
        int n = nums.size();
        int third = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < third)
                return true;
            while (!st.empty() && st.top() < nums[i])
            {
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 1, 4, 2};
    cout << "132 Pattern? : " << s.find132pattern(nums);
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm: 

- condition nums[i] < nums[k] < nums[j] 
- We keep track of the max element(nums[j]) in the stack, and keep track of the second largest element
  in the variable "third" nums[k]. If we find any element smaller than "third", i.e nums[i], that means
  we found the sequence, hence we return true. If the loop ends, we return false.

*/