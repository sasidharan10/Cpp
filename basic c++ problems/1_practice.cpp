#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
void printSubsequences(int index, vector<int>v, vector<int>&ans)
{
    
    if(index==v.size())
    {
        if(ans.empty())
        {
            cout<<"{}"<<endl;
            return;
        }
        vector<int>::iterator i;
        for (i = ans.begin(); i !=ans.end(); i++)
        {
            cout<<*i<<" "; 
        }
        cout<<endl;
        return;
    }
    printSubsequences(index+1,v, ans);
    ans.push_back(v[index]);
    printSubsequences(index+1,v, ans);
    ans.pop_back();
}
int main()
{
    vector<int> v{56, 97, 34};
    vector<int> ans;
    int index = 0;
    printSubsequences(index, v, ans);
    return 0;
    return 0;

}