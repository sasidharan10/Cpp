#include<iostream>
using namespace std;
int count=0;      /// global variable
class math
{
    public:
    math()
    {
            count++;
    cout<<"Constructor is called: "<< count<<endl;
    }
    ~math()
    {
        count--;
        cout<<"Destructor is called: "<< count<<endl;
    }
};
int main()
{
    cout<<"Main function is called..."<<endl;
    cout<<"1st object created"<<endl;
    math m;
    {  // this is a block, when this block is finished, memory is deallocated
        cout<<"Entering into Block..."<<endl;
        cout<<"2 more objects created"<<endl;
        math m2, m3;
        cout<<"Exiting block..."<<endl;
    }  
    cout<<"main function is finished..."<<endl;
    return 0;
}

/*

- Destructor is also a special member function like constructor. Destructor destroys
  the class objects created by constructor. 
- Destructor has the same name as their class name preceded by a tilde (~) symbol.
- It is not possible to define more than one destructor. 
- The destructor is only one way to destroy the object create by constructor. Hence destructor
  can-not be overloaded.
- Destructor neither requires any argument nor returns any value.
- It is automatically called when object goes out of scope i.e, when object is no longer
  required in the code. 

*/