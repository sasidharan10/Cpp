#include <bits/stdc++.h>
using namespace std;
class entry
{
public:
    int key;
    int val;
    entry(int key, int val)
    {
        this->key = key;
        this->val = val;
    }
};
class MyHashMap
{
public:
    int SIZE = 769;
    forward_list<entry> map[769];
    MyHashMap()
    {
    }
    void put(int key, int value)
    {
        int bucket = key % SIZE;
        if (map[bucket].empty())
        {
            entry el(key, value);
            map[bucket].push_front(el);
        }
        else
        {
            forward_list<entry> temp = map[bucket];
            for (auto &&i : temp)
            {
                if (i.key == key)
                {
                    i.val = value;
                    return;
                }
            }
            entry el(key, value);
            temp.push_front(el);
        }
    }

    int get(int key)
    {
        int bucket = key % SIZE;
        forward_list<entry> temp = map[bucket];
        if (temp.empty())
            return -1;
        for (auto &&i : temp)
        {
            if (i.key == key)
                return i.val;
        }
        return -1;
    }
    void remove(int key)
    {
        int bucket = key % SIZE;
        forward_list<entry> temp = map[bucket];
        forward_list<entry> newList;
        for (auto &&i : temp)
        {
            if (i.key != key)
            {
                entry el(i.key, i.val);
                newList.push_front(el);
            }
        }
        map[bucket].clear();
        map[bucket] = newList;
    }
};
int main()
{
    MyHashMap map;
    map.put(0, 10);
    map.put(1, 20);
    map.put(2, 30);
    map.put(3, 40);
    map.put(4, 50);
    map.put(5, 60);
    cout << "get(0): " << map.get(0) << endl;
    cout << "get(1): " << map.get(1) << endl;
    cout << "get(2): " << map.get(2) << endl;
    cout << "remove(2)" << endl;
    map.remove(2);
    cout << "get(2): " << map.get(2) << endl;
    cout << "get(7): " << map.get(7) << endl;
    map.put(2, 25);
    cout << "put(2): " << endl;
    cout << "get(2): " << map.get(2) << endl;
    return 0;
    return 0;
}