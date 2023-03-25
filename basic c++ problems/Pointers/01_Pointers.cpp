#include <iostream>
using namespace std;
int main()
{
    int a = 10, b = 20;
    int *p;
    char *q;
    float *r;
    double *s;
    long double *t;
    short int *u;
    void *v; // generic pointer. it cannot be mapped to a variable
    p = &a;
    cout << "a : " << a << endl;   // value of a
    cout << "&a : " << &a << endl; // address of a
    cout << "p : " << p << endl;   // value of p(address of a)
    cout << "&p : " << &p << endl; // address of variable p
    cout << "*p : " << *p << endl; // value at address it is pointing to (dereferencing)
    *p = b;
    cout<<"*p = b"<<endl;
    cout << "p : " << p << endl; // we can see since only the value is changed but the address remains same
    cout << "*p : " << *p << endl;

    cout << "sizeof(a) : " << sizeof(a) << endl;
    cout << "\np+1 : " << p + 1 << endl;     // p+1 means it moves to next address by 4 bytes
    cout << "*(p+1) : " << *(p + 1) << endl; // gives garbage value because we didnt store anything in that address

    return 0;
}

// so the size of all pointer varibles are 4 bytes.(datatype doesnt matter as just stores address)
// pointerss and variables should have same datatype because pointer is used to dereference the variabes also
// void pointers can store the address only

// cout<<"sizeof(p) : "<<sizeof(p)<<endl;
// cout<<"sizeof(q) : "<<sizeof(q)<<endl;
// cout<<"sizeof(r) : "<<sizeof(r)<<endl;
// cout<<"sizeof(s) : "<<sizeof(s)<<endl;
// cout<<"sizeof(t) : "<<sizeof(t)<<endl;
// cout<<"sizeof(u) : "<<sizeof(u)<<endl;