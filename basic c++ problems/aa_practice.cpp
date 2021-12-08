#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int *left=new int[n1];
    int *right=new int[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[l+i];
    for(int i=0;i<n2;i++)
        right[i]=arr[mid+i+1];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];
        delete left;
        delete right;
}
void mergesort(vector<int> &arr,int l,int r){
    if(l>=r) return ;
    int mid=l+(r-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main(){
    int a[] = {6, 5, 8, 4, 7, 2, 3, 1,9};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> arr(a,a+n);
    mergesort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {       
        cout<<arr[i];
    }
    
}
