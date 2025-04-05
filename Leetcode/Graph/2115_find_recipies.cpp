#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - simulation
    vector<string> findAllRecipes2(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        // T.C : (n^2 * m)
        // S.C : O(n+S)

        int n = recipes.size();
        int t = n;
        vector<string> res;
        vector<bool> cooked(n, false);
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end());
        while (t--)
        {
            for (int i = 0; i < n; i++)
            {
                bool canbeCooked = true;
                for (int j = 0; j < ingredients[i].size(); j++)
                {
                    if (suppliesSet.find(ingredients[i][j]) == suppliesSet.end())
                    {
                        canbeCooked = false;
                        break;
                    }
                }
                if (canbeCooked && !cooked[i])
                {
                    res.push_back(recipes[i]);
                    suppliesSet.insert(recipes[i]);
                    cooked[i] = true;
                }
            }
        }
        return res;
    }

    // Optimal - using topo sort
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        // T.C : O(n + m + S)
        // S.C : O(n + S)
        
        int n = recipes.size();
        unordered_map<string, vector<int>> adj;
        unordered_map<string, int> inDegree;
        vector<string> res;
        for (int i = 0; i < n; i++)
        {
            string recipe = recipes[i];
            inDegree[recipe] = ingredients[i].size();
            for (int j = 0; j < ingredients[i].size(); j++)
            {
                adj[ingredients[i][j]].push_back(i);
            }
        }
        queue<string> que;
        for (int i = 0; i < supplies.size(); i++)
        {
            que.push(supplies[i]);
        }
        while (!que.empty())
        {
            string item = que.front();
            que.pop();
            for (auto &&nbr : adj[item])
            {
                inDegree[recipes[nbr]]--;
                if (inDegree[recipes[nbr]] == 0)
                {
                    res.push_back(recipes[nbr]);
                    que.push(recipes[nbr]);
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<string> recipes = {"bread", "sandwich", "burger"}, supplies = {"yeast", "flour", "meat"};
    vector<vector<string>> ingredients = {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}};
    vector<string> ans = s.findAllRecipes(recipes, ingredients, supplies);
    cout << "Result: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

Youtube: https://www.youtube.com/watch?v=4Tixc5mU-Pk

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Topological%20Sorting/Find%20All%20Possible%20Recipes%20from%20Given%20Supplies.cpp

algorithm:

- Brute Force Approach:

- simulate the problem

- Optimal Approach:

- using topo sort, build a graph, ingredient -> recipe, and calculate the indegree.

*/

/*

2115. Find All Possible Recipes from Given Supplies

You have information about n different recipes. You are given a string array recipes and a 2D string
array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the
needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i]
may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you
have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".

Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]],
supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".

Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".

Constraints:

n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.

*/

/*
************* Java Code **************

    public static List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        int n = recipes.length;
        HashMap<String, List<String>> adj = new HashMap<>();
        HashMap<String, Integer> inDegree = new HashMap<>();
        List<String> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String recipe = recipes[i];
            inDegree.put(recipe, ingredients.get(i).size());

            for (int j = 0; j < ingredients.get(i).size(); j++) {
                adj.computeIfAbsent(ingredients.get(i).get(j), x -> new ArrayList<>()).add(recipe);
            }
        }
        Queue<String> que = new LinkedList<>();
        for (int i = 0; i < supplies.length; i++) {
            que.offer(supplies[i]);
        }
        while (!que.isEmpty()) {
            String item = que.poll();

            if (!adj.containsKey(item))
                continue;

            for (String nbr : adj.get(item)) {
                inDegree.put(nbr, inDegree.get(nbr) - 1);
                if (inDegree.get(nbr) == 0) {
                    res.add(nbr);
                    que.offer(nbr);
                }
            }
        }
        return res;
    }

*/