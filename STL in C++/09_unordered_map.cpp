#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<int,string>m{{1,"A"},{2,"B"},{3,"C"},{4,"D"},{5,"E"}};
    cout<<"Map: ";
    for (auto &&i : m)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }
    cout << "m.size() : " << m.size() << endl;
    cout << "First element: " << m.begin()->first << " : " << m.begin()->second << endl;
    m.insert({6,"F"});
    cout << "Found \"3\" ?: ";
    if (m.find(3) != m.end()) // only finds key
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "Count(C): " << m.count(2);
    return 0;
}


/*

- Internally uses hash tables.
- Insertion, search and removal takes constant time.
- Elements won't be sorted.

*/