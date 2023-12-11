#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0)
            {
                int sum = st.top() + asteroids[i];
                // case: 1
                if (sum > 0)
                {
                    asteroids[i] = 0;
                }
                // case: 2
                else if (sum < 0)
                {
                    st.pop();
                }
                // case: 3
                else
                {
                    st.pop();
                    asteroids[i] = 0;
                }
            }
            if (asteroids[i] != 0)
            {
                st.push(asteroids[i]);
            }
        }
        int m = st.size();
        vector<int> ans(m, 0);
        int j = m - 1;
        while (!st.empty())
        {
            ans[j] = st.top();
            st.pop();
            j--;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{10, 2, -5};
    vector<int> ans = s.asteroidCollision(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/asteroid-collision

Youtube: https://www.youtube.com/watch?v=7isfomHzzno

algorithm:

- -ve element moves left and +ve element moves right.
- If no collision occurs, we just push that element into the stack
- A collision occurs, only when first element is +ve, and next element 
  element is -ve. vice versa, means, both move away from each other.
- If collision occurs:
- Case1 : sum > 0, means st.top() is greater than "cur", it means the "cur"
  element gets destroyed. hence we just assign "cur" = 0, to break the 
  loop, and move to next element. (assigning it 0, also wont get pushed into the stack).
- Case: 2 sum < 0, means "cur" > st.top(), means st.top() gets destroyed, and we
  need to compare with next element in stack, hence we just pop, and the loop continues.
- Case 3: sum == 0, means "cur" == st.top(), means both gets destroyed, hence we just
  pop the element from stack, and move to next element, hence we assign cur = 0.
- Assigning cur = 0, does 2 works, one, we break the loop, and the cur element is 
  not pushed into the stack.
  
*/

/*

735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign
represents its direction (positive meaning right, negative meaning left).
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids
meet, the smaller one will explode. If both are the same size, both will explode.
Two asteroids moving in the same direction will never meet.

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

*/