#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
public:
    vector<int> parent, size;
    disjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // TC: O(n*m) * O(4 * alpha)  +  O(n*m) * O(4 * alpha)  +  O(n * MlogM)
        // SC: O(n*m) + O(n * 2)

        int n = accounts.size();
        unordered_map<string, int> mp;
        disjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            int m = accounts[i].size();
            // j = 0, is the name of the account older, not needed
            for (int j = 1; j < m; j++)
            {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end())
                    mp[mail] = i;
                else
                    ds.unionBySize(i, mp[mail]);
            }
        }

        // merging mails having same account name
        vector<vector<string>> mergedMail(n);
        for (auto it : mp)
        {
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergedMail[node].push_back(mail);
        }

        // adding the name, then the mail ids, in sorted order
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].size() == 0)
                continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            int m = mergedMail[i].size();
            for (int j = 0; j < m; j++)
            {
                temp.push_back(mergedMail[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<string>> accounts{{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                    {"John", "johnsmith@mail.com", "john00@mail.com"},
                                    {"Mary", "mary@mail.com"},
                                    {"John", "johnnybravo@mail.com"}};
    vector<vector<string>> ans = s.accountsMerge(accounts);
    cout << "E-mail list after Merging: " << endl;
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        int m = ans[i].size();
        cout << ans[i][0] << " : ";
        for (int j = 1; j < m; j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/account-merge/1

leetcode: https://leetcode.com/problems/accounts-merge/description/

Youtube: https://www.youtube.com/watch?v=FMwpt_aQOGw&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=50

algorithm:

- Using DisjointSet DS, we merge the mail-ids, having same account holder.
- THen we merge those mails, then sort it and return the result.

*/