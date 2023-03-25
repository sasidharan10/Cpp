#include<iostream>
using namespace std;
int* add(int a,int b)
{
    int *c=new int;  
    // int c;  // normal variable c will give error
    *c=a + b;
    return c;
}
int main()
{
    int a=10,b=20;
    int *c;
    c=add(a,b);
    cout<<"C : "<<*c<<endl;
    delete c;
    return 0;
}
/*
- when we return normal c, the memory gets deallocated when function ends. 
  so only garbage value is present in that addrress. thats why we need 
  a dynamic variable whose memorry will not be deallocated untill we delete it
*/