#include <iostream>
#include <queue>
using namespace std;
int main()
{
    deque<int> dq;
    for (int i = 1; i < 6; i++)
    {
        dq.push_back(i);
    }
    cout << "front : " << dq.front() << endl;
    cout << "back  : " << dq.back() << endl;
    cout << "size  : " << dq.size() << endl;
    cout << "empty : " << dq.empty() << endl;
    cout << "Pop (front)" << endl;
    dq.pop_front();
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