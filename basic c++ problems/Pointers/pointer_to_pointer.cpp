#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int* p=&a;
    int** q = &p;
    int ***r=&q;

    cout<<"a (value): "<<a<<endl;  
    cout<<"*p (pointes to a) : "<<*p<<endl;
    cout<<"p (address) : "<<p<<endl;
    cout<<"*q (pointes to p) : "<<*q<<endl;
    cout<<"q (address) : "<<q<<endl;
    cout<<"*r (pointes to q) : "<<*r<<endl;
    cout<<"r (address): "<<r<<endl;

    cout<<"\n*p : "<<*p<<endl;
    cout<<"**q : "<<**q<<endl;
    cout<<"***r : "<<***r<<endl;
    return 0;
}