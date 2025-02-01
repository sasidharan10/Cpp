#include <bits/stdc++.h>
using namespace std;
class LFUCache
{
private:
    unordered_map<int, list<vector<int>>::iterator> mp; // key -> address of list of vector{key, value, freq}
    map<int, list<vector<int>>> freq;                   // freq -> list of vector{key, value, freq}
    int cap;
    int size;

public:
    LFUCache(int capacity)
    {
        cap = capacity;
        size = 0;
    }

    void makeMostFrequentlyUsed(int key)
    {
        // get that vector, by dereferencing the list iterator
        vector<int> &vec = (*mp[key]);
        int val = vec[1];
        int fq = vec[2];         // frequency
        freq[fq].erase(mp[key]); // popping from the list

        if (freq[fq].empty()) // if list empty, then remove that freq list.
        {
            freq.erase(fq);
        }

        fq++;                                             // increasing its freq
        freq[fq].push_front(vector<int>({key, val, fq})); // adding into new freq list
        mp[key] = freq[fq].begin();                       // updating its address in the map
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        vector<int> &vec = *(mp[key]); // dereferencing the list iterator, gives the vector
        int value = vec[1];
        makeMostFrequentlyUsed(key);

        return value;
    }

    void put(int key, int value)
    {
        if (cap == 0)
            return;

        if (mp.find(key) != mp.end())
        {
            vector<int> &vec = *(mp[key]);
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if (size < cap)
        {
            int fq = 1;
            freq[fq].push_front(vector<int>({key, value, fq}));
            mp[key] = freq[fq].begin();
            size++;
        }
        else // size is full, hence we need to remove the LFU key, and add the new key
        {
            list<vector<int>> &ddl_list_to_delete = freq.begin()->second;

            int key_to_delete = ddl_list_to_delete.back()[0];

            ddl_list_to_delete.pop_back(); // deleting the LFU key.

            if (ddl_list_to_delete.empty())
            {
                freq.erase(freq.begin()->first);
            }

            freq[1].push_front(vector<int>({key, value, 1})); // adding the new key

            mp.erase(key_to_delete);   // deleting old key in mp
            mp[key] = freq[1].begin(); // adding new key with address in mp
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

leetcode: https://leetcode.com/problems/lfu-cache/description/

Youtube: https://www.youtube.com/watch?v=-Vch0tHAsOM
 
Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Design/LFU%20Cache.cpp

algorithm:

- Optimal Approach:

- refer video

*/

/*

460. LFU Cache

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. 
When the cache reaches its capacity, it should invalidate and remove the least frequently used key before 
inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), 
the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with 
the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use 
counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]

Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
 
Constraints:

1 <= capacity <= 10^4
0 <= key <= 10^5
0 <= value <= 10^9
At most 2 * 10^5 calls will be made to get and put.

*/

/*
************* Java Code **************



*/