#include <iostream>
#include <queue>
using namespace std;
int main()
{
    deque<int> dq;
    deque<int> temp;
    for (int i = 1; i < 6; i++)
    {
        dq.push_back(i);
        temp.push_back(i);
    }
    cout << "front : " << dq.front() << endl;
    cout << "back  : " << dq.back() << endl;
    cout << "size  : " << dq.size() << endl;
    cout << "empty : " << dq.empty() << endl;
    cout << "Pop (front)" << endl;
    dq.pop_front();
    int n= dq.size();
    for (int i = 0; i < n; i++)
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout<<endl;
    dq=temp;
    cout << "size  : " << dq.size() << endl;
    cout << "front : " << dq.front() << endl;
    cout << "Pop (back)" << endl;
    dq.pop_back();
    cout << "size  : " << dq.size() << endl;
    cout << "back  : " << dq.back() << endl;
    dq.push_front(1);
    // cout << "front : " << dq.front() << endl;
    return 0;
}


/*

- Double ended queue
- Allows insertion and deletion from both ends
- TC: O(n) for insertion and deletion
- Storage size is dynamic
- Expansion of deque is cheaper than vector.

*/