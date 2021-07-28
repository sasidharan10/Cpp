#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
int kth_smallest(vector<vector<int>>v,int k)
{
    // priority_queue<int,vector<int>,greater<>>pq;
    priority_queue<int>pq;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            pq.push(v[i][j]);
            if(pq.size()>k)
                pq.pop();
        }
    }
    // int ans;
    // while (k--)
    // {
    //     ans=pq.top();
    //     pq.pop();
    // }
    // return ans;
    return pq.top();
}

// binary search method incomplete

// int kth_smallest(vector<vector<int>>v,int k)
// {
//     int row=v.size();
//     int col= v[0].size();
//     int low=v[0][0];
//     int high=v[row-1][col-1];
//     int mid=(low+high)/2;
//     int count=0;
//     while(low<=high)
//     {
//         mid=(low+high)/2;
//         if(k>mid)
//     }
// }
int main()
{
    vector<vector<int>>v = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    int k=3;
    cout<<"kth smallest : "<<kth_smallest(v,k)<<endl;
}