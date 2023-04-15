#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s{4, 5, 3, 1, 2};
    unordered_set<int>::iterator it;
    cout << "Unordered set: ";
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "s.begin() : " << *s.begin() << endl; // returns iterator. used for sorting ,etc
    cout << "s.size() : " << s.size() << endl;
    cout << "s.max_size() : " << s.max_size() << endl;
    cout << "s.empty() : " << s.empty() << endl;
    cout << "s.count(3) : " << s.count(3) << endl;
    s.insert(7);
    s.erase(7);
    for (auto &&i : s)
        cout << i << " ";
    cout<<endl;
    if (s.find(1) != s.end())
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}

/*

- similar to sets.
- Elements won't be sorted.
- Insertion, search and removal takes constant time.
- Internally it uses hashing to store the elements, hence takes constant time.


*/