#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class student
{
    string name;
    int rno;

public:
    void getData();
    void printData();
};
void student::getData()
{
    cout << "Enter name : ";
    cin >> name;
    cout << "Enter roll no : ";
    cin >> rno;
}
void student::printData()
{
    cout << "\nName is : " << name << endl;
    cout << "Roll no : " << rno << endl;
}
int main()
{
    student s[3];
    for (int i = 0; i < 3; i++)
    {
        s[i].getData();
        s[i].printData();
    }
    return 0;
}