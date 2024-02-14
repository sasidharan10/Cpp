#include <bits/stdc++.h>
using namespace std;
class MyHashMap
{
public:
    int map[10001];
    MyHashMap()
    {
        fill(map, map + 10001, -1);
    }

    void put(int key, int value)
    {
        map[key] = value;
    }

    int get(int key)
    {
        return map[key];
    }

    void remove(int key)
    {
        map[key] = -1;
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
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/design-hashmap/description/

Youtube: https://www.youtube.com/watch?v=ISir207RuKQ

algorithm: resize to map[1000001]

*/