#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int> v, int target)
{
    unordered_map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        if (m.find(target - v[i]) != m.end())
        {
            ans.push_back(m[target - v[i]]);
            ans.push_back(i);
            return ans;
        }
        else
            m[v[i]] = i;
    }
    return ans;
}
int main()
{
    vector<int> v{8, 2, 14, 4, 5, 6};
    int target = 20;
    v = twoSum(v, target);
    for (auto i : v)
        cout << i << " : ";
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/two-sum/

Youtube: 

algorithm: 

*/