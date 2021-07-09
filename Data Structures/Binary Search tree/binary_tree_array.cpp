#include<iostream>
#include<algorithm>
using namespace std;
char tree[10];
void rootNode(char x)
{
    if(tree[0]!='\0')
        cout<<"Tree already has a root"<<endl;
    else
        tree[0]=x;
}
void left(char x,int parent)
{
    if(tree[parent]=='\0')
        cout<<"Cannot set child for "<<parent<<endl;
    else
        tree[(2*parent)+1]=x;
}
void right(char x,int parent)
{
    if(tree[parent]=='\0')
        cout<<"Cannot set child for "<<parent<<endl;
    else
        tree[(2*parent)+2]=x;
}
void print()
{
    cout<<"Tree is : ";
    for (int i = 0; i < 10; i++)
    {
        if(tree[i]!='\0')
            cout<<tree[i]<<" ";
        else
            cout<<"_ ";
    }
    
}
int main()
{
    rootNode('A');
    left('B',0);
    right('C',0);
    left('D',1);
    left('E',2);
    print();
    return 0;
}