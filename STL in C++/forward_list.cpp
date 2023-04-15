#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> l{1, 2, 3};
    forward_list<int>::iterator i;
    cout << "\nList: ";
    for (i = l.begin(); i != l.end(); i++)
    {
        cout << *i << " ";
        // l.pop_front();
    }
    l.clear();       // clears the list
    l.push_front(3); // pushes 3
    l.assign(5, 1);  // pushes 5 ones to the list, overrides current list
    cout << "\nList after assign(5, 1): ";
    for (auto &&i : l)
        cout << i << " ";
    l.assign({2, 3, 4}); // overrides the list
    l.pop_front();       // removes first element
    cout << "\nList after pop_front(): ";
    for (auto &&i : l)
        cout << i << " ";
    i = l.insert_after(l.begin(), 9); // inserts element, after begin()
    cout << "\nList after insert_after(l.begin(), 9): ";
    for (auto &&i : l)
        cout << i << " ";
    i = l.erase_after(l.begin()); // erases 1 element after ptr
    cout << "\nList after l.erase_after(l.begin()): ";
    for (auto &&i : l)
        cout << i << " ";
    l.erase_after(l.begin(), l.end()); // erases element from first pointer to all. first element is not erased
    cout << "\nEmpty?: " << l.empty();
    l.assign({1, 2, 3, 4, 4, 5}); // removes the mentioned element
    l.remove(4);
    cout << "\nList after l.remove(4): ";
    for (auto &&i : l)
        cout << i << " ";
    l.remove_if([](int x)
                { return x > 2; });
    cout << "\nList after l.remove_if(x>2): ";
    for (auto &&i : l)
        cout << i << " ";
    return 0;
}