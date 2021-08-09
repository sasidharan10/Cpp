#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    for (int i = 1; i < 6; i++)
    {
        q.push(i);
    }
    cout << "front : " << q.front() << endl;
    cout << "back  : " << q.back() << endl;
    cout << "size  : " << q.size() << endl;
    cout << "empty : " << q.empty() << endl;
    cout << "Pop (front)" << endl;
    q.pop();
    cout << "size  : " << q.size() << endl;
    cout << "front : " << q.front() << endl;
    return 0;
}