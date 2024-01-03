#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;
        for (int it : rooms[0])
        {
            q.push(it);
        }
        vis[0] = true;
        while (!q.empty())
        {
            int room = q.front();
            q.pop();
            vis[room] = true;
            for (int it : rooms[room])
            {
                if (!vis[it])
                    q.push(it);
            }
        }
        for (bool it : vis)
        {
            if (!it)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> rooms{{1, 3}, {3, 0, 1}, {2}, {0}};
    // vector<vector<int>> rooms{{1}, {2}, {3}, {}};
    cout << "Can visit all rooms?: " << s.canVisitAllRooms(rooms) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/keys-and-rooms

Youtube:

algorithm:

- BFS or DFS
- its said we can visit 0th room at first.
- Hence we store the keys from 0th room.
- Now we traverse the queue, and those rooms as visited and
  add keys to the queue, only if its not visited.
- After queue gets empty, we traverse through "vis" array, and check
  if all rooms are visited, if yes, return true, else false.
  
*/

/*

841. Keys and Rooms

There are n rooms labeled from 0 to n - 1 and all the rooms are locked
except for room 0. Your goal is to visit all the rooms. However, you
cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each
key has a number on it, denoting which room it unlocks, and you can take
all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain
if you visited room i, return true if you can visit all the rooms, or false otherwise.

Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation:
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.

*/