#include <iostream>
#include <map>
using namespace std;
int main()
{
    multimap<string, int> mm{{"A", 1}, {"B", 1}, {"C", 2}, {"C", 3}, {"D", 4}, {"E", 5}};
    // cout<<mm["A"]<<endl;   // not allowed, as it causes abmiguity
    cout << "Multi map: " << endl;
    for (auto &&i : mm)
    {
        cout << i.first << " : " << i.second << endl;
    }
    cout << "Size: " << mm.size() << endl;
    cout << "Max size: " << mm.max_size() << endl;
    cout << "First element: " << mm.begin()->first << " : " << mm.begin()->second << endl;
    mm.insert({"A", 4});
    cout << "Found \"E\" ?: ";
    if (mm.find("E") != mm.end()) // only finds key
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "Count(C): " << mm.count("C");
    return 0;
}



/*

- Similar to map, but it can store duplicate keys.
- we cannot access values using keys, since multiple keys can be present in multimap.
- Data structure is not defined by standard, but its assumed that it uses red-black tree.

*/