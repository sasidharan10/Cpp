#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class student
{
public:
    string name;
    int marks;
    bool operator<(student &s) const
    {
        return marks > s.marks;
    }
};
int main()
{
    student s[4] = {{"d", 10}, {"b", 30}, {"c", 20}, {"a", 40}};
    priority_queue<student, vector<student>, less<>> pq;
    for (int i = 0; i < 4; i++)
    {
        cout << "Name: " << s[i].name << ", Marks: " << s[i].marks << endl;
    }
    cout << "Priority queue: " << endl;
    for (int i = 0; i < 4; i++)
    {
        pq.push(s[i]);
    }
    while (!pq.empty())
    {
        cout << "Name: " << pq.top().name << ", Marks: " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}