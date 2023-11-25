#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class student
{
    string name;
    int rno;

public:
    void getData(string, int);
    void printData();
    bool operator==(student &s3)
    {
        if (name == s3.name && rno == s3.rno)
            return true;
        else
            return false;
    }
};
void student::getData(string name, int rno)
{
    this->name = name;
    this->rno = rno;
}
void student::printData()
{
    cout << "\nName is : " << name << endl;
    cout << "Roll no : " << rno << endl;
}

int main()
{
    student s1;
    s1.getData("sasi", 10);
    s1.printData();
    student s2 = s1; // coping s1 to s2
    if (s1 == s2)
        cout << "Same" << endl;
    else
        cout << "Not same" << endl;
    return 0;
}

/*

- "this" keyword is used to refer the members of the class
- If variables in class and function arguments have same name,
  then to avoid ambiguity, we use "this" pointer to refer class members.

*/