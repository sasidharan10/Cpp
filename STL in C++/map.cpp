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



*/