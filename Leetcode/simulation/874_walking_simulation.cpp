#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPathBlocked(int i, int j, unordered_set<string> &obs)
    {
        string temp = to_string(i) + '_' + to_string(j);
        if (obs.find(temp) != obs.end())
            return true;
        else
            return false;
    }
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        // TC: O(n) * K * O(m) ~= O(n)
        // SC: O(m) where m = obstacles.

        // since we are using set to search the obstacles, O(m) can be considered as O(1).
        // since K's range is [1, 9], it can also be considered as O(1).

        int n = commands.size();
        int m = obstacles.size();
        unordered_set<string> obs;
        string temp;
        for (int i = 0; i < m; i++)
        {
            temp = to_string(obstacles[i][0]) + '_' + to_string(obstacles[i][1]);
            obs.insert(temp);
        }
        int directions[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // N, E, S, W
        int x = 0, y = 0;
        int maxi = 0;
        int d = 0;
        for (int i = 0; i < n; i++)
        {
            int c = commands[i];
            if (c == -2)
            {
                d = (d + 3) % 4;
            }
            else if (c == -1)
            {
                d = (d + 1) % 4;
            }
            else
            {
                int dx = directions[d][0];
                int dy = directions[d][1];
                for (int step = 0; step < c; step++)
                {
                    if (isPathBlocked(x + dx, y + dy, obs))
                        break;
                    x = x + dx;
                    y = y + dy;
                }
                maxi = max(maxi, x * x + y * y);
            }
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    vector<int> commands{4, -1, 4, -2, 4};
    vector<vector<int>> obstacles = {{2, 4}};
    cout << "Result: " << s.robotSim(commands, obstacles) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/walking-robot-simulation

Youtube: https://www.youtube.com/watch?v=K8lMDgaAn4w
Neetcode: https://www.youtube.com/watch?v=wpglWC6mnLg

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Simulation/Walking%20Robot%20Simulation.cpp

algorithm:

- Optimal Approach:

- We will be simulating the problem as given.
- To find the directions, we use the directions[], where the directions are in order N E S W.
- So, incase we need to turn left, we can just move 1 step backward in the array and find the
  current direction, vice versa. We will be traversing this array, as a circular array.
- We will convert the axis of each obstacle into a string, and store it in a hashset for
  faster access. (x,y) will be separated by '_'.
- Now we traverse through the command, and if the given command is a direction change, we change it.
- If the command is to move 'c' steps, then we towards the current direction from 0 - c.
- As we move each step, we check if the new axis is present in the obstacle Hashset.
- If yes, we break the loop, or we move towards it.
- Once the inner loop is done, we update the "maxi".
- return maxi.

*/

/*

874. Walking Robot Simulation

A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot can receive a
sequence of these three possible types of commands:

-2: Turn left 90 degrees.
-1: Turn right 90 degrees.
1 <= k <= 9: Move forward k units, one unit at a time.
Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi).
If the robot runs into an obstacle, then it will instead stay in its current location and move
on to the next command.

Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if
the distance is 5, return 25).

Note:

North means +Y direction.
East means +X direction.
South means -Y direction.
West means -X direction.
There can be obstacle in [0,0].

Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: The robot starts at (0, 0):
1. Move north 4 units to (0, 4).
2. Turn right.
3. Move east 3 units to (3, 4).
The furthest point the robot ever gets from the origin is (3, 4), which squared
is 32 + 42 = 25 units away.

Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: The robot starts at (0, 0):
1. Move north 4 units to (0, 4).
2. Turn right.
3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
4. Turn left.
5. Move north 4 units to (1, 8).
The furthest point the robot ever gets from the origin is (1, 8), which squared is 12 + 82 = 65 units away.

Example 3:

Input: commands = [6,-1,-1,6], obstacles = []
Output: 36
Explanation: The robot starts at (0, 0):
1. Move north 6 units to (0, 6).
2. Turn right.
3. Turn right.
4. Move south 6 units to (0, 0).
The furthest point the robot ever gets from the origin is (0, 6), which squared is 62 = 36 units away.

Constraints:

1 <= commands.length <= 10^4
commands[i] is either -2, -1, or an integer in the range [1, 9].
0 <= obstacles.length <= 10^4
-3 * 10^4 <= xi, yi <= 3 * 10^4
The answer is guaranteed to be less than 2^31

*/

/*
************* Java Code **************

    public static boolean isPathBlocked(int i, int j, HashSet<String> obs) {
        String temp = Integer.toString(i) + '_' + Integer.toString(j);
        if (obs.contains(temp))
            return true;
        else
            return false;
    }

    public static int robotSim(int[] commands, int[][] obstacles) {
        int n = commands.length;
        int m = obstacles.length;
        HashSet<String> obs = new HashSet<>();
        String temp;
        for (int i = 0; i < m; i++) {
            temp = Integer.toString(obstacles[i][0]) + '_' + Integer.toString(obstacles[i][1]);
            obs.add(temp);
        }
        int[][] directions = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int x = 0, y = 0;
        int maxi = 0;
        int d = 0;
        for (int i = 0; i < n; i++) {
            int c = commands[i];
            if (c == -2) {
                d = (d + 3) % 4;
            } else if (c == -1) {
                d = (d + 1) % 4;
            } else {
                int dx = directions[d][0];
                int dy = directions[d][1];
                for (int step = 0; step < c; step++) {
                    if (isPathBlocked(x + dx, y + dy, obs))
                        break;
                    x = x + dx;
                    y = y + dy;
                }
                maxi = Math.max(maxi, x * x + y * y);
            }
        }
        return maxi;
    }

*/