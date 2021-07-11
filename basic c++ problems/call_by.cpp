#include<iostream>
using namespace std;
// Call by value
void swap(int a, int b)
{ 
    int temp = a;           
    a = b;               
    b = temp;            
}

// Call by reference using pointers
void swapPointer(int* a, int* b)
{ 
    int temp = *a;           
    *a = *b;             
    *b = temp;          
}

// Call by reference using C++ reference Variables
// int & 
void swapReferenceVar(int &a, int &b)
{ 
    int temp = a;
    a = b;  
    b = temp;
}

int main(){
    int x =4, y=5;
    cout<<"Before swapping..."<<endl;
    cout<<"x : "<<x<<" and y : "<<y<<endl;
    swap(x, y); // This will not swap a and b
    cout<<"x : "<<x<<" and y : "<<y<<" (Call by value)"<<endl; 
    swapPointer(&x, &y); //This will swap a and b using pointer reference
    cout<<"x : "<<x<<" and y : "<<y<<" (Call by value)"<<endl;
    swapReferenceVar(x, y); //This will swap a and b using reference variables
    cout<<"x : "<<x<<" and y : "<<y<<" (Call by value)"<<endl; 
    return 0;
}
