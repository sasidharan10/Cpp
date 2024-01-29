#include <bits/stdc++.h>
using namespace std;

// Brute force
class MyQueue2
{
public:
    stack<int> st1, st2;
    MyQueue2()
    {
    }
    // O(n)
    void push(int x)
    {
        while (!st1.empty())
        {
            int temp = st1.top();
            st1.pop();
            st2.push(temp);
        }
        st1.push(x);
        while (!st2.empty())
        {
            int temp = st2.top();
            st2.pop();
            st1.push(temp);
        }
    }
    // O(1)
    int pop()
    {
        int temp = st1.top();
        st1.pop();
        return temp;
    }
    // O(1)
    int peek()
    {
        return st1.top();
    }
    // O(1)
    bool empty()
    {
        return st1.empty();
    }
};

// optimal
class MyQueue
{
public:
    stack<int> input, output;
    MyQueue()
    {
    }
    // O(1)
    void push(int x)
    {
        input.push(x);
    }
    // O(1) amortised
    int pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                int temp = input.top();
                input.pop();
                output.push(temp);
            }
        }
        int temp = output.top();
        output.pop();
        return temp;
    }
    // O(1) amortised
    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                int temp = input.top();
                input.pop();
                output.push(temp);
            }
        }
        return output.top();
    }
    // O(1)
    bool empty()
    {
        return input.empty() && output.empty();
    }
};
int main()
{
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/implement-queue-using-stacks

Youtube: https://www.youtube.com/watch?v=3Et9MrMc02A

algorithm:

- Brute Force Approach:

- We use 2 stacks, where whenever we get any push operation
  we try to reerse the stack using st2, and add the element,
  and again reverse the stack by putting it back to st1.
- Hence the order is maintained just like a queue.

- Optimal Approach:

- 2 stacks "input" and "output".
- All inputs are pushed into "input" stack.
- Any pop() or peek() operation comes, 
  we check if "output" stack is empty, if yes, 
  add all elements from "input" to "output" stack(order gets reversed)
  then we can do the pop() or peek() on the "output" stack.
- isEmpty(), check if both stacks are empty or not.

*/

/*

232. Implement Queue using Stacks

Implement a first in first out (FIFO) queue using only two stacks. 
The implemented queue should support all the functions of a normal 
queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push 
to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. 
You may simulate a stack using a list or deque (double-ended queue) as 
long as you use only a stack's standard operations.
 
Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

*/