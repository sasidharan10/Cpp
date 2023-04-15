#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l{1, 2, 3, 4, 5, 5, 5};
    for (auto &&i : l)
        cout << i << " ";
    cout << "\nl.front(): " << l.front() << endl;
    cout << "l.back(): " << l.back() << endl;
    cout << "size: " << l.size() << endl;
    l.push_front(99);
    l.pop_front();
    l.push_back(99);
    l.pop_back();
    l.insert(l.begin(), 7);
    l.remove(5); // removes all occurence of 5
    for (auto &&i : l)
        cout << i << " ";
    l.erase(l.begin(), --l.end());
    cout << endl;
    for (auto &&i : l)
        cout << i << " ";
    return 0;
}

/*

- It is a doubly linked list
- Faster insert and delete operation, compared to array and vectors.
- Not sorted

*/