#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int a[] = {6, 5, 8, 4, 7, 2, 3, 1,9};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<max_element(a,a+n)-a<<endl;
    vector<int>v(a,a+n);
    cout<<max_element(v.begin(),v.end())-v.begin()<<endl;
    return 0;
    
}
