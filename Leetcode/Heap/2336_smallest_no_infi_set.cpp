#include <bits/stdc++.h>
using namespace std;

// Optimal
class SmallestInfiniteSet
{
public:
    vector<bool> vec;
    int i;
    SmallestInfiniteSet()
    {
        i = 1;
        vec.resize(1001, true);
    }

    int popSmallest()
    {
        int result = i;
        vec[i] = false;
        for (int j = i + 1; j <= 1001; j++)
        {
            if (vec[j])
            {
                i = j;
                break;
            }
        }
        return result;
    }

    void addBack(int num)
    {
        vec[num] = true;
        if (num < i)
            i = num;
    }
};

// Using priority queue
class SmallestInfiniteSet
{
public:
    unordered_set<int> cache;
    priority_queue<int, vector<int>, greater<int>> pq;
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
            pq.push(i);
    }

    int popSmallest()
    {
        int temp = pq.top();
        pq.pop();
        cache.insert(temp);
        return temp;
    }

    void addBack(int num)
    {
        if (cache.find(num) != cache.end())
        {
            pq.push(num);
            cache.erase(num);
        }
    }
};
int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/smallest-number-in-infinite-set/description

Youtube: https://www.youtube.com/watch?v=qiSjBraBzLM

algorithm:

- Since the numbers will be from 1-1000, we use a vector to store all numbers.
- we use a pointer 'i' to point to the smallest element. and keep it updated
  when pop() or addBack() operation is done
- In second approach, we use PQ, this approach will work numbers > 1000 also,
  but the no of calls should be 1000.
  
*/

/*

2336. Smallest Number in Infinite Set

You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if 
it is not already in the infinite set.

Example 1:

Input
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", 
"addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
Output
[null, null, 1, 2, 3, null, 1, 4, 5]

Explanation
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                   // is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.

*/