#include <iostream>
using namespace std;
int main()
{
    int *p = new int[3]{1, 2, 3}; // declaration with initialisation of dynamic array
    int *q = new int(10);         // dynamic allocation of a varible with initialisation
    int *r;                       // pointer varible, only declaration
    cout<<"*q: "<<*q<<endl;                  
    cout<<"*r: "<<*r<<endl;                  
    cout<<"*p: "<<*p<<endl;                  
    r = new int;                  // dynamic allocation of the varible
    *r = 500;                     // asssigning value to the variable
    int *s;                       // pointer vaiable
    s = new int[3];               // pointer poining to an array(size=3) in heap
    s[0] = 90;                    // initialising values
    s[1] = 80;
    s[2] = 70;
    // *s={1};  // eqiuvalent to s[0]=1
    cout << "p[1] : " << p[1] << endl;
    cout << "s[0] : " << s[0] << endl;
    cout << "s[2] : " << s[2] << endl;
    cout << "*s : " << *s << endl;
    cout << "*r : " << *r << endl;
    cout << "*q : " << *q << endl;
    // memory should be deallocated or it will cause memory leak
    delete q;
    delete r;
    delete[] p;
    delete[] s;
    return 0;
}

/*

Memory leak: Dynamically allocated memory are present in "heap" section which
are accessed by pointer variables. once the function call ends, the pointer
variables are destroyed, but the memory space in "heap", to which these variables 
were pointing, are not deallocated (not cleared), and needs to be explicitly
deallocated. these consumed spaces are unusable and waste of memory.

*/