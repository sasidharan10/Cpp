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
    cout << "Queue: " << endl;
    int n= q.size();
    for (int i = 0; i < n; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}


/*

- It is FIFO data structure.
- It allows push at back and pop from front.
- All operations have TC: O(1)

*/