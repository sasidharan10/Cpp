#include<iostream>
using namespace std;

class Employee
{
    private:
        int a, b, c;  // can only be accessed within the class and by their functions
    public:
        int d, e;   // can be accessed afrom any class and functions
        void setData(int a1, int b1, int c1); // Declaration
        void getData(){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of d is "<<d<<endl;
            cout<<"The value of e is "<<e<<endl;
        }
};

void Employee :: setData(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
}

int main(){
    Employee harry;
    // harry.a = 134; -->This will throw error as a is private
    harry.d = 34;
    harry.e = 89;
    harry.setData(1,2,4);
    harry.getData();
    return 0;
}

// we were able to access the private data members using a public function which acts like a middleware agent
// so  private data members can be accessed by indirectly using functions which are public