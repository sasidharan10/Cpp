#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <unordered_map>
#include <set>
#include <vector>
#include <map>
using namespace std;
// typedef unordered_map<string,int>::iterator mit;
struct comp
{
    bool operator()(const pair<string, int> &p1, const pair<string, int> &p2)
    {
        return p1.second < p2.second;
    }
};
bool compare(pair<string, int> &p1, pair<string, int> &p2)
{
    return p1.second < p2.second;
}

void valSort1(unordered_map<string, int> &m)
{
    /*

    we know map sorts its elements w.r.t keys. hence we will create a map, and assign,
    its key to value and vise-versa.
    
    */

    vector<pair<string, int>> v;
    map<int, string> sm;
    unordered_map<string, int>::iterator i;
    for (i = m.begin(); i != m.end(); i++)
    {
        sm[i->second] = i->first;
    }
    cout << "\nUsing unordered map: " << endl;
    map<int, string>::iterator it;
    for (it = sm.begin(); it != sm.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
}
void valSort2(unordered_map<string, int> &m)
{
    /*
    
    Here, we used the in-built sort() to sort the map. we used a comparator
     function (compare()),which tells the sort function, to sort the vector based on second parameter.
    
    */
    vector<pair<string, int>> v;
    for (auto it : m)
    {
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), compare);
    cout << "\nsorted by value: " << endl;
    for (auto &i : v)
        cout << i.first << " : " << i.second << endl;
}
void valSort3(unordered_map<string, int> &m)
{

    /*
    
    here, we use operator overloading, which used the class name as a parameter, 
    and we define the operator function, to sort based on second value.
    
    */
    set<pair<string, int>, comp> s(m.begin(), m.end());
    cout << "\nUsing set: " << endl;
    for (auto i : s)
        cout << i.first << " : " << i.second << endl;
}
int main()
{
    unordered_map<string, int> m;
    m["sasi"] = 3;
    m["messi"] = 9;
    m["ramos"] = 4;
    m["ronaldo"] = 15;
    m["mbappe"] = 12;
    m["haaland"] = 1;
    m["van Dijk"] = 19;
    cout << "map: " << endl;
    unordered_map<string, int>::iterator i;
    for (i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << " : " << i->second << endl;
    }
    valSort1(m);
    valSort2(m);
    valSort3(m);
    return 0;
}
