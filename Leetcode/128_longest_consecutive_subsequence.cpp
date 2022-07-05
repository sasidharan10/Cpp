#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>
using namespace std;
int longestSequence(vector<int>nums)
{
    unordered_set<int>s(nums.begin(),nums.end());
    int longestStreak=0;
    int currentStreak=0,currentNum=0;
    for (int i = 0; i < nums.size(); i++)
    {
        // we need first number of sequence, and to count the streak from it, and ignore other numbers
        if(s.find(nums[i]-1)==s.end())  
        {
            currentStreak=1;
            currentNum=nums[i];
            while (s.find(currentNum+1)!=s.end())
            {
                currentNum++;
                currentStreak++;
            }
            longestStreak=max(longestStreak,currentStreak);
        }
    }
    return longestStreak;
}
int main()
{
    vector<int> v{0,3,7,16,2,5,8,13,12,4,6,0,1,11,15};
    cout<<"Longest consecutive subsequence: "<<longestSequence(v);
    return 0;
}