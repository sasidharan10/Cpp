#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

void insetNode(int n, node *head)
{
    if(head==NULL)
    {
        head->data=n;
        head->next=NULL;
        return;
    }
}
int main()
{
    node *head=NULL;
    int n=5;
    for (int i = 1; i <= n; i++)
    {
        
    }
    
    return 0;
}