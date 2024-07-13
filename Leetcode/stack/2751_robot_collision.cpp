#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        // TC: O(n) + O(nlogn) + O(2n) ~ O(nlogn)
        // SC: O(n)
        
        int n = positions.size();
        vector<int> indices;
        for (int i = 0; i < n; i++)
        {
            indices.push_back(i);
        }

        auto lambda = [&](int &i, int &j)
        {
            return positions[i] < positions[j];
        };

        sort(indices.begin(), indices.end(), lambda);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int currIndex = indices[i];
            if (directions[currIndex] == 'R')
                st.push(currIndex);
            else
            {
                // healths[currIndex] > 0 means curr robot is still alive.
                while (!st.empty() && healths[currIndex] > 0)
                {
                    int topIndex = st.top();
                    // if curr robot is greater, it destroys its peer.
                    if (healths[currIndex] > healths[topIndex])
                    {
                        healths[currIndex]--;
                        healths[topIndex] = 0;
                        st.pop();
                    }
                    // if the peer is greater, it destroys the curr robot.
                    else if (healths[currIndex] < healths[topIndex])
                    {
                        healths[topIndex]--;
                        healths[currIndex] = 0;
                    }
                    // if both are same, they both get destroyed.
                    else
                    {
                        healths[currIndex] = 0;
                        healths[topIndex] = 0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (healths[i] > 0)
                ans.push_back(healths[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    // vector<int> positions = {1, 2, 5, 6}, healths = {10, 10, 11, 11};
    // string directions = "RLRL";
    vector<int> positions = {3, 5, 2, 6}, healths = {10, 10, 15, 12};
    string directions = "RLRL";
    vector<int> ans = s.survivedRobotsHealths(positions, healths, directions);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/robot-collisions

Youtube: https://www.youtube.com/watch?v=fkcA9zvP7_w

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Stack/Robot%20Collisions.cpp

algorithm:

- Optimal Approach:

- Similar question: LC 735
- Robots when they are against each other, they attack.
- which means only possible combination is RL.
- When 2 robots are in same direction(LL, RR) or in opposite direction(LR), they wont attack each other.
- First we have to sort the arrays, in terms of how the positions[] array elements are placed.
- Instead of using a map, and keep the positions[] elements as key and other elements as value, we can 
  just create a indices array(0 - n-1), and then sort it in terms os positions[]. 
- We use a lambda function to do this type of sorting.
- We take a stack, where we stoer all robots having directions == 'R'.
- If we encounter any robots with directions =='L', then we perform the operations as per the above
  code.
- Note that, we are only changing the healths[i] value, when it is encountering an attack.
- eg "LLRR", here the first 2 robots, wont be atacked, hence we wont push it into stack, and well
  as its healths[i] value wont be changed.
  
*/

/*

2751. Robot Collisions

There are n 1-indexed robots, each having a position on a line, health, and movement direction.

You are given 0-indexed integer arrays positions, healths, and a string directions
(directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

All robots start moving on the line simultaneously at the same speed in their given directions.
If two robots ever share the same position while moving, they will collide.

If two robots collide, the robot with lower health is removed from the line, and the health of
the other robot decreases by one. The surviving robot continues in the same direction it was
going. If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions, in the same order
that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2
(if survived), and so on. If there are no survivors, return an empty array.

Return an array containing the health of the remaining robots (in the order they were given in
the input), after no further collisions can occur.

Note: The positions may be unsorted.

Example 1:

Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in the same
direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].

Example 2:

Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
Output: [14]
Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide,
and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4
will collide and since robot 4's health is smaller, it gets removed, and robot 3's health
becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].

Example 3:

Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
Output: []
Explanation: Robot 1 and robot 2 will collide and since both have the same health, they are both
removed. Robot 3 and 4 will collide and since both have the same health, they are both removed.
So, we return an empty array, [].

Constraints:

1 <= positions.length == healths.length == directions.length == n <= 10^5
1 <= positions[i], healths[i] <= 10^9
directions[i] == 'L' or directions[i] == 'R'
All values in positions are distinct

*/

/*
************* Java Code **************



*/