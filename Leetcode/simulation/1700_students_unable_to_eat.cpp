#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - using queue
    int countStudents2(vector<int> &students, vector<int> &sandwiches)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = students.size();
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            que.push(students[i]);
        }
        int cnt = 0;
        int i = 0;
        int res = n;
        while (!que.empty() && cnt < que.size() && i < n)
        {
            if (que.front() == sandwiches[i])
            {
                que.pop();
                i++;
                cnt = 0;
                res--;
            }
            else
            {
                cnt++;
                int temp = que.front();
                que.pop();
                que.push(temp);
            }
        }
        return res;
    }

    // Optimal
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = students.size();
        int s0 = 0, s1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (students[i] == 0)
                s0++;
        }
        s1 = n - s0;
        for (int i = 0; i < n; i++)
        {
            int sand = sandwiches[i];
            if ((sand == 0 && s0 == 0) || (sand == 1 && s1 == 0))
                return n - i;
            if (sand == 0)
                s0--;
            else
                s1--;
        }
        return 0;
    }
};
int main()
{
    Solution s;
    vector<int> students = {1, 1, 1, 0, 0, 1}, sandwiches = {1, 0, 0, 0, 1, 1};
    cout << "Result: " << s.countStudents(students, sandwiches) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

Youtube: https://www.youtube.com/watch?v=M0lhTkhUlp4

Code Link:

algorithm:

- Brute Force Approach:

- Simulate the scenario using queue and stack.

- Optimal Approach:

- We take count of 0's and 1's types of students.
- We traverse the sandwich arr, and decrement the corresponding sandwich count.
- Once any of the 2 sandwich cnt becomes 0, and we still have that sandwich in
  the sandwich arr, then we cannot distribute any more sandwiches. 
- return n - i.

*/

/*

1700. Number of Students Unable to Eat Lunch

The school cafeteria offers circular and square sandwiches at lunch break, referred
to by numbers 0 and 1 respectively. All students stand in a queue. Each student
either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students.
The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the
stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich
and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is
the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and
students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0
is the front of the queue). Return the number of students that are unable to eat.

Example 1:

Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.

Example 2:

Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3

*/

/*
************* Java Code **************

// using queue

public static int countStudents(int[] students, int[] sandwiches) {
        int n = students.length;
        Queue<Integer> que = new LinkedList();
        for (int i = 0; i < n; i++) {
            que.offer(students[i]);
        }
        int cnt = 0;
        int i = 0;
        int res = n;
        while (!que.isEmpty() && cnt < que.size() && i < n) {
            if (que.peek() == sandwiches[i]) {
                que.poll();
                i++;
                cnt = 0;
                res--;
            } else {
                cnt++;
                int temp = que.poll();
                que.offer(temp);
            }
        }
        return res;
    }

*/