#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "size: " << s.size() << endl;
    cout << "top: " << s.top() << endl;
    s.pop();
    cout << "top: " << s.top() << endl;
    cout << "Stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\nEmpty: " << s.empty();
    return 0;
}

/*



*/