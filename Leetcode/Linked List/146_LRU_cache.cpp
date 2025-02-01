#include <bits/stdc++.h>
using namespace std;

// Brute force: Gives TLE (using vector<pair>)
class LRUCache2
{
public:
    vector<pair<int, int>> mp;
    int n;
    LRUCache2(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        for (int i = 0; i < mp.size(); i++)
        {
            if (mp[i].first == key)
            {
                pair<int, int> temp = mp[i];
                mp.erase(mp.begin() + i);
                mp.push_back(temp);
                return temp.second;
            }
        }
        return -1;
    }

    void put(int key, int value)
    {
        for (int i = 0; i < mp.size(); i++)
        {
            if (mp[i].first == key)
            {
                mp.erase(mp.begin() + i);
                mp.push_back({key, value});
                return;
            }
        }
        if (mp.size() == n)
        {
            mp.erase(mp.begin());
            mp.push_back({key, value});
        }
        else
            mp.push_back({key, value});
    }
};

// Optimal - using map and DLL.
class LRUCache
{
public:
    list<int> ddl;
    unordered_map<int, pair<list<int>::iterator, int>> cache;
    int n;
    LRUCache(int capacity)
    {
        n = capacity;
    }
    void makeMostRecentlyUsed(int key)
    {
        ddl.erase(cache[key].first);
        ddl.push_front(key);
        cache[key].first = ddl.begin();
    }

    int get(int key)
    {
        if(cache.find(key)!=cache.end())
        {
            int val = cache[key].second;
            makeMostRecentlyUsed(key);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(cache.find(key)!=cache.end())
        {
            makeMostRecentlyUsed(key);
            cache[key].second = value;
        }
        else
        {
            ddl.push_front(key);
            cache[key] = {ddl.begin(), value};
            n--;
        }

        if(n < 0) 
        {
            cache.erase(ddl.back());
            ddl.pop_back();
            n++;
        }
    }
};

int main()
{
    LRUCache *lRUCache = new LRUCache(2);
    (*lRUCache).put(1, 1); // cache is {1=1}
    (*lRUCache).put(2, 2); // cache is {1=1, 2=2}
    int input = 0;
    input = (*lRUCache).get(1); // return 1
    (*lRUCache).put(3, 3);      // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    input = (*lRUCache).get(2); // returns -1 (not found)
    (*lRUCache).put(4, 4);      // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    input = (*lRUCache).get(1); // return -1 (not found)
    input = (*lRUCache).get(3); // return 3
    input = (*lRUCache).get(4); // return 4
    return 0;
}

/*

link: https://www.romaglushko.com/blog/design-lru-cache/

leetcode: https://leetcode.com/problems/lru-cache

Youtube: https://www.youtube.com/watch?v=81h8O-0U5oo

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Design/LRU%20Cache.cpp

algorithm:

- Brute Force Approach:

- using vector, gives TLE

- Optimal Approach:

- Using Doubly linked list, and hashmap.

*/

/*

146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair
to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Constraints:

1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 105 calls will be made to get and put.

*/

/*
************* Java Code **************

class LRUCache {
    class Node {
        int key;
        int val;
        Node prev;
        Node next;

        Node(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }

    Node head = new Node(-1, -1);
    Node tail = new Node(-1, -1);
    int cap;
    HashMap<Integer, Node> m = new HashMap<>();

    public LRUCache(int capacity) {
        cap = capacity;
        head.next = tail;
        tail.prev = head;
    }

    private void addNode(Node newnode) {
        Node temp = head.next;

        newnode.next = temp;
        newnode.prev = head;

        head.next = newnode;
        temp.prev = newnode;
    }

    private void deleteNode(Node delnode) {
        Node prevv = delnode.prev;
        Node nextt = delnode.next;

        prevv.next = nextt;
        nextt.prev = prevv;
    }

    public int get(int key) {
        if (m.containsKey(key)) {
            Node resNode = m.get(key);
            int ans = resNode.val;

            m.remove(key);
            deleteNode(resNode);
            addNode(resNode);

            m.put(key, head.next);
            return ans;
        }
        return -1;
    }

    public void put(int key, int value) {
        if (m.containsKey(key)) {
            Node curr = m.get(key);
            m.remove(key);
            deleteNode(curr);
        }

        if (m.size() == cap) {
            m.remove(tail.prev.key);
            deleteNode(tail.prev);
        }

        addNode(new Node(key, value));
        m.put(key, head.next);
    }
}

*/