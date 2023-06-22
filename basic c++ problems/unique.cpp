#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v{1, 2, 2, 3, 2, 2, 3, 3, 3, 4, 4};

    auto it = unique(v.begin(), v.end());
    cout << "Vector after pushing all duplicates values: ";
    for (auto i = v.begin(); i != it; i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << "Full vector along with duplicates: ";
    for (auto &&i : v)
        cout << i << " ";

    return 0;
}

/*

- unique() pushes all consecutive duplicate elements to last and returns an iterator,
  pointing to all dulicate elements.
- it only pushes duplicate elements, only if they are placed right next to each other,
  or it will ignore it.
- vector size wont be changed.
- to remove all duplicate elements, we can first sort the array, then use unique() to
- to push all duplicate elements at last.
- erase the duplicate elements from the given pointer, till the end.
  
*/