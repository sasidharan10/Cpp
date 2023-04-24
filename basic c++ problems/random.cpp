#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{ 
    int x;
    int l=0, h=10;

    // random_integer = lowest + rand() % range

    for (int i = 0; i < 20; i++)
    {
        int ran=l+rand()%h;
        cout<<ran<<endl;
    }
    
    return 0;
}