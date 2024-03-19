#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        // TC: O(n * log(26))
        // SC: O(n)

        int m = tasks.size();
        vector<int> mp(26, 0);
        for (int i = 0; i < m; i++)
        {
            mp[tasks[i] - 'A']++;
        }

        priority_queue<int> pq;
        for (int freq : mp)
        {
            if (freq > 0)
                pq.push(freq);
        }
        int time = 0;
        while (!pq.empty())
        {
            vector<int> temp;
            for (int i = 0; i < n + 1; i++)
            {
                if (!pq.empty())
                {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for (int fq : temp)
            {
                if (fq > 0)
                    pq.push(fq);
            }

            if (pq.empty())
                time += temp.size();
            else
                time += n + 1;
        }
        return time;
    }
};
int main()
{
    Solution s;
    // vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E'};
    int n = 2;
    cout << "Minimum number of Intervals Required: " << s.leastInterval(tasks, n) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

Code Link:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

621. Task Scheduler

You are given an array of CPU tasks, each represented by letters A to Z, and a
cooling time, n. Each cycle or interval allows the completion of one task.
Tasks can be completed in any order, but there's a constraint: identical tasks
must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two cycles before doing A again.
The same applies to task B. In the 3rd interval, neither A nor B can be done,
so you idle. By the 4th cycle, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3
intervals. This leads to idling twice between repetitions of these tasks.

*/

/*
************* Java Code **************



*/