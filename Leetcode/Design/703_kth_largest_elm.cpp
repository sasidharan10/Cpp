#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (int x : nums)
        {
            pq.push(x);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};
int main()
{
    Solution s;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/kth-largest-element-in-a-stream

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Since we have to return kth largest element, we will create a min-heap and we will
  maintain its size as k.
- So it will always have k smallest elements in the heap.
- The top element will be the smallest among the k elements, or in other words, it is 
  the kth largest element.
- Whenever we add an element, we only add it, if its greater than the top element, and 
  also maintain the size of te heap.

*/

/*

703. Kth Largest Element in a Stream

Design a class to find the kth largest element in a stream. Note that it is the kth largest
element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and
the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the
kth largest element in the stream.

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

Constraints:

1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for the kth element.

*/

/*
************* Java Code **************

    public static int k;
    public static PriorityQueue<Integer> pq;
    public KthLargest(int k, int[] nums) {
        this.k = k;
        pq = new PriorityQueue<>();
        for (int x : nums)
        {
            pq.offer(x);
            if (pq.size() > k)
                pq.poll();
        }
    }
    
    public int add(int val) {
        pq.offer(val);
        if (pq.size() > k)
            pq.poll();
        return pq.peek();
    }

*/