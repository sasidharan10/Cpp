#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    a = {1, 2, 3, 4, 5};
    a.reserve(10); // assigning the size before for efficient performance
    vector<int> b{10, 20, 30, 40, 50, 60};
    b.reserve(4);
    cout << "at(1) : " << a.at(1) << endl; // throws exception if array out of bound
    cout << "a[2] : " << a[2] << endl;     // prints the element of given index
    cout << "a.front(): " << a.front() << endl;
    cout << "a.begin() : " << *a.begin() << endl; // returns iterator. used for sorting ,etc
    cout << "a.back() : " << a.back() << endl;
    cout << "a.end() : " << *a.end() << endl;
    cout << "*(a.end()-1) : " << *(a.end() - 1) << endl;
    cout << "a.size() : " << a.size() << endl;
    cout << "a.max_size() : " << a.max_size() << endl;
    b.clear(); // clears all element
    cout << "b.empty() : " << b.empty() << endl;
    a.push_back(6);
    a.push_back(7);
    a.pop_back();
    cout << "Elements in a : ";
    for (int i : a)
        cout << i << " ";
    b.resize(4);              // resizes to 4
    b.emplace(b.begin(), 10); // (iterator,value)
    b.emplace_back(20);       // (iterator,value)
    b.insert(b.begin(), 5);   // (iterator,value)
    a.erase(a.begin());       // (iterator,value)
    cout << "\nElements in b : ";
    for (auto i : b)
        cout << i << " ";

    // initialise a vector with all values 0
    vector<int> vec(5, 0); // vec(size,value);
    return 0;
}
