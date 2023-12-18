#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
};
class FoodRatings
{
public:
    /*
    T.C -
    FoodRatings - O(n)
    changeRating - log(n) due to erase function used in ordered_set
    highestRated - O(1)

    S.C - O(n) in all maps
    */
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, set<pair<int, string>>> cuisineFoodRating;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            foodRating.insert({foods[i], ratings[i]});
            foodToCuisine.insert({foods[i], cuisines[i]});
            cuisineFoodRating[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        int oldRating = foodRating[food];
        string cuisine = foodToCuisine[food];
        cuisineFoodRating[cuisine].erase({-oldRating, food});
        cuisineFoodRating[cuisine].insert({-newRating, food});
        foodRating[food] = newRating;
    }

    string highestRated(string cuisine)
    {
        pair<int, string> temp = *cuisineFoodRating[cuisine].begin();
        return temp.second;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/design-a-food-rating-system

Youtube: https://www.youtube.com/watch?v=SF13GD8FPxM

algorithm:

- We use 3 DS, one to map food to its rating, then to map food to its cuisine and then map
  cuisine with all its food with its rating.
- cuisineFoodRating DS, the cuisine contains all the foods along with its rating. 
  as per the question we need to return the food with highest rating of a particular
  cuisine. If the rating are same for mltiple food, we need to return the food, which 
  is lexicographically sorted.
- To achieve this, we use a set<pair<int, string>>, which will store the food and rating
  in sorted order. First it will sort in terms of rating, then if ratings are same, it will 
  sort based on food by default.
- By default, it will be sorted ascending order, hence our result will be present at last.
  but if we try to fetch the last element, we will return wrong answer if 2 or more foods
  have the same rating.
- EX: (13, noodles), (16, burger), (16, sushi) 
- here, the function will return (16, sushi), but the answer is (16, burger).
  Either we can write comparator function to sort it in decreasing orde
  or we can store the ratings in negative, which will aslo give the desired result.
- EX: (-16, burger), (-16, sushi), (13, noodles)

*/

/*

2353. Design a Food Rating System

Design a food rating system that can do the following:

Modify the rating of a food item listed in the system.
Return the highest-rated food item for a type of cuisine in the system.
Implement the FoodRatings class:

FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes
the system. The food items are described by foods, cuisines and ratings,
all of which have a length of n.
foods[i] is the name of the ith food,
cuisines[i] is the type of cuisine of the ith food, and
ratings[i] is the initial rating of the ith food.
void changeRating(String food, int newRating) Changes the rating
of the food item with the name food.
String highestRated(String cuisine) Returns the name of the food
item that has the highest rating for the given type of cuisine.
If there is a tie, return the item with the lexicographically smaller name.
Note that a string x is lexicographically smaller than string y
if x comes before y in dictionary order, that is, either x is a
prefix of y, or if i is the first position such that x[i] != y[i],
then x[i] comes before y[i] in alphabetic order.

Example 1:

Input
["FoodRatings", "highestRated", "highestRated", "changeRating",
"highestRated", "changeRating", "highestRated"]
[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"],
["korean", "japanese", "japanese", "greek", "japanese", "korean"],
[9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16],
["japanese"], ["ramen", 16], ["japanese"]]

Output
[null, "kimchi", "ramen", null, "sushi", null, "ramen"]

Explanation
FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi",
"moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese",
"greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
foodRatings.highestRated("korean"); // return "kimchi"
                                    // "kimchi" is the highest rated korean food with a rating of 9.
foodRatings.highestRated("japanese"); // return "ramen"
                                      // "ramen" is the highest rated japanese food with a rating of 14.
foodRatings.changeRating("sushi", 16); // "sushi" now has a rating of 16.
foodRatings.highestRated("japanese"); // return "sushi"
                                      // "sushi" is the highest rated japanese food with a rating of 16.
foodRatings.changeRating("ramen", 16); // "ramen" now has a rating of 16.
foodRatings.highestRated("japanese"); // return "ramen"
                                      // Both "sushi" and "ramen" have a rating of 16.
                                      // However, "ramen" is lexicographically smaller than "sushi".



*/