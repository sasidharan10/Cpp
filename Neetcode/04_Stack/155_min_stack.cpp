#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
    stack<int> st;
    stack<int> minSt;
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        // if min stack is empty, then return INT_MAX
        int mini = min(val, !minSt.empty() ? minSt.top() : INT_MAX);
        minSt.push(mini);
    }

    void pop()
    {
        st.pop();
        minSt.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};

int main()
{
    MinStack m;
    vector<int> nums{1, 2, 3, 4, 5};
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/min-stack/

Youtube: https://www.youtube.com/watch?v=qkLl7nAwDPo

Code Link:

algorithm:

- Brute Force Approach:

- Iterate over the stack, and return the mini element from it.

- Optimal Approach:

- maintain 1 more stack, which will be used to track the minimum element, up until the elements we stored
  in the main stack.
- While poping and pushing, make changes in both the stack.

*/

/*

155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:

-2^31 <= val <= 2^31 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.


*/

/*
************* Java Code **************

    class MinStack {

        private Stack<Integer> stack;
        private Stack<Integer> minStack;

        public MinStack() {
            stack = new Stack<>();
            minStack = new Stack<>();
        }

        public void push(int val) {
            stack.push(val);
            int mini = Math.min(val, !minStack.isEmpty() ? minStack.peek() : Integer.MAX_VALUE);
            minStack.push(mini);
        }

        public void pop() {
            stack.pop();
            minStack.pop();
        }

        public int top() {
            return stack.peek();
        }

        public int getMin() {
            return minStack.peek();
        }
    }

*/