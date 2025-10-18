#include <bits/stdc++.h>
using namespace std;
class MyHashSet
{
public:
    int siz = 100;
    vector<list<int>> m;
    MyHashSet()
    {
        m.resize(siz);
    }
    int hash(int key)
    {
        return key % siz;
    }

    void add(int key)
    {
        int i = hash(key);
        if (Search(key) == m[i].end())
        {
            m[i].push_back(key);
            cout << "Added(" << key << ")" << endl;
        }
    }

    void remove(int key)
    {
        int i = hash(key);
        list<int>::iterator it = Search(key);
        if (it != m[i].end())
        {
            m[i].erase(it);
            cout << "Removed(" << key << ")" << endl;
        }
    }

    bool contains(int key)
    {
        int i = hash(key);
        if (Search(key) != m[i].end())
            return true;
        else
            return false;
    }
    list<int>::iterator Search(int key)
    {
        int i = hash(key);
        return find(m[i].begin(), m[i].end(), key);
    }
};

int main()
{
    MyHashSet myHashSet;
    // MyHashSet myHashSet = new MyHashSet();
    myHashSet.add(1);                                          // set = [1]
    myHashSet.add(2);                                          // set = [1, 2]
    cout << "contains(1)?: " << myHashSet.contains(1) << endl; // return True
    cout << "contains(3)?: " << myHashSet.contains(3) << endl; // return False, (not found)
    myHashSet.add(3);                                          // set = [1, 2]
    cout << "contains(2)?: " << myHashSet.contains(2) << endl; // return True
    myHashSet.remove(2);                                       // set = [1]
    cout << "contains(2)?: " << myHashSet.contains(2) << endl; // return False, (already removed)
    cout << "Ended successfully!!!" << endl;
    return 0;
}