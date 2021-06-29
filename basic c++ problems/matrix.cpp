#include<iostream>
using namespace std;
int main()
{
    int r1=2,c1=3;
    int r2=3,c2=2;
    int a[2][2]={{5,6},{7,8}};
    int b[2][2]={{1,2},{3,4}};
    int c[2][3]={{1,2,3},{4,5,6}};
    int d[3][2]={{10,11},{20,21},{30,31}};
    int add[2][2],sub[2][2];

    // addition

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            add[i][j]=a[i][j]+b[i][j];
        }
    }
    cout<<"Additon is : "<<endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<add[i][j]<<" ";
        }
        cout<<endl;
    }

    // subtraction

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sub[i][j]=a[i][j]-b[i][j];
        }
    }
    cout<<"Subtraction is : "<<endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<sub[i][j]<<" ";
        }
        cout<<endl;
    }

    // Multiplication

    if(c1==r2)
        cout<<"Multiplication is possible"<<endl;
    else
        cout<<"Multiplication is NOT possible (c1!=r2)!!!"<<endl;
    
    // note : the resultant matrix for (r1,c1)*(r2,c2) will have (r1,c2) rows and columns
    int pro[2][2];
    int sum=0;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < r2; k++)
            {
                sum+=c[i][k]*d[k][j];
            }
            pro[i][j]=sum;
            sum=0;
        }
    }
    cout<<"Multiplication is : "<<endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<pro[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}