#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<set>
using namespace std;
void subsets1(int index,vector<int>v,vector<int>temp,  set<vector<int>>&ans)
{
    /*
    brute force

    we use set of vectors to store all the possible combinations and duplicates
    will be eliminated by the set

    */
    if(index==v.size())
    {
        if(temp.empty())
            temp.push_back(0);
        ans.insert(temp);
        return;
    }
    temp.push_back(v[index]);
    subsets1(index+1,v,temp,ans);
    temp.pop_back();
    subsets1(index+1,v,temp,ans);
}
int main()
{
    vector<int> v{1,2,2};
    set<vector<int>>ans;
    set<int>s({2,3,1});
    vector<int>temp;
    subsets1(0,v,temp,ans);
    set<vector<int>>::iterator it;
    set<int>::iterator itt;
    vector<int>::iterator i;
    for (auto i : ans)
    {
        for (auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}