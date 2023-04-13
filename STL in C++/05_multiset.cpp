#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    multiset<int>ms;
    ms={3,5,7,9,1,3,4,6};
    cout<<"Front: "<<*ms.begin()<<endl;
    cout<<"Multiset: ";
    for (auto &&i : ms)
    {
        cout<<i<<" ";
    }
    
}

/*

- Internally uses Red-Black tree.
- allows duplicate elements.
- Insertion, removal TC= O(logn)

*/