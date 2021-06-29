#include<iostream>
using namespace std;
void name(char *s)
{
    cout<<"Name is : "<<s<<endl;;
}
int add(int a , int b)
{
    return a+b;
}
int main()
{
    int c;
    int (*p)(int,int);  // function pointer
    p=&add;  // pointer pointing to the function
    c=(*p)(20,30); // function call using pointer
    cout<<"C is : "<<c<<endl;

    char s[]="Joe Root";
    void  (*ptr)(char*);  // declaring a pointer to a function
    ptr=name;  // assigning the address to the pointer
    ptr(s);  // calling the function using the pointer
    // (*ptr)(s); // both are same(calling the function)
    return 0;
}

// the return type of the pointer while declaring should be same and it should have the datatypes of the parameters