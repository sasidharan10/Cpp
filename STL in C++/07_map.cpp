#include <iostream>
#include <iterator>
#include <string>
#include <map>
using namespace std;
int main()
{
    map<string, int> m; // map creation
    m.insert(pair<string, int>("B", 20));
    m.insert(pair<string, int>("C", 30));
    m.insert(pair<string, int>("A", 10));
    m.insert({"E", 30});
    m.insert({"D", 30}); //({key,value})
    auto it = m.find("A");
    m.insert(it, {"B", 101}); //(iterator,{key,value})

    // iiterator creation for traversing
    map<string, int>::iterator itr;

    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << " : " << itr->second << endl;
    }

    cout << "Found \"E\" ?: ";
    if (m.find("E") != m.end()) // only finds key
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "m['A'] : " << m["A"] << endl;
    cout << "m.at('B') : " << m.at("B") << endl;
    m.erase(m.begin(), m.find("B")); // erase using key
    cout << "m.lower_bound('C')->first : " << m.lower_bound("C")->first << endl;
    cout << "m.upper_bound('C)->first : " << m.upper_bound("C")->first << endl;
    cout << "m.count('D') : " << m.count("D") << endl; // returns 1 if key present
    m.clear();                                         // delete all values
    cout << "m.empty() : " << m.empty() << endl;
    // m1.swap(m2); maps gets swapped
    return 0;
}

/*

- map stores key in ORDER and ELIMINATES DUPLICATE VALUES based on key.
- it uses self balancing binary tree(AVL, Red-black tree)
- we can have duplicates values, but not keys.

note: 
- When using an iterator to traverse a map, we get a pointer to a pair of key-value
  elements in the map. This pointer can be accessed using the '->' operator,
  which is used to access the member elements of a pointer to a struct or class object.
- On the other hand, when using a for-each loop to iterate through a map, we get
  a reference to the key-value elements in the map directly. The key-value elements
  are returned as a reference to a pair object, and we can access the members of the
  pair object using the '.' operator, just like we would access the members of any
other struct or class object.


*/