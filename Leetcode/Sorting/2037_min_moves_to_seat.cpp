#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - Using sorting
    int minMovesToSeat2(vector<int> &seats, vector<int> &students)
    {
        // TC: O(nlogn) + O(nlogn) + O(n)
        // SC: O(1)

        int n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += abs(seats[i] - students[i]);
        }
        return res;
    }

    // Optimal - Using array as map
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        // TC: O(n) + O(100)
        // SC: O(100) + O(100)
        
        int n = seats.size();
        int seatsMap[101] = {0};
        int studentMap[101] = {0};
        for (int i = 0; i < n; i++)
        {
            seatsMap[seats[i]]++;
            studentMap[students[i]]++;
        }

        int i = 0, j = 0;
        int res = 0;
        while (i <= 100 && j <= 100)
        {
            if (seatsMap[i] == 0)
                i++;
            if (studentMap[j] == 0)
                j++;

            if (i <= 100 && j <= 100 && seatsMap[i] != 0 && studentMap[j] != 0)
            {
                res += abs(i - j);
                seatsMap[i]--;
                studentMap[j]--;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> seats = {4, 1, 5, 9}, students = {1, 3, 2, 6};
    cout << "Result: " << s.minMovesToSeat(seats, students) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

Youtube: https://www.youtube.com/watch?v=sU-yjrJTnYs

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Minimum%20Number%20of%20Moves%20to%20Seat%20Everyone.cpp

algorithm:

- Optimal Approach:

-

*/

/*

2037. Minimum Number of Moves to Seat Everyone

There are n seats and n students in a room. You are given an array seats of length n,
where seats[i] is the position of the ith seat. You are also given the array students
of length n, where students[j] is the position of the jth student.

You may perform the following move any number of times:

Increase or decrease the position of the ith student by 1 (i.e., moving the ith student
from position x to x + 1 or x - 1)
Return the minimum number of moves required to move each student to a seat such that no
two students are in the same seat.

Note that there may be multiple seats or students in the same position at the beginning.

Example 1:

Input: seats = [3,1,5], students = [2,7,4]
Output: 4
Explanation: The students are moved as follows:
- The first student is moved from from position 2 to position 1 using 1 move.
- The second student is moved from from position 7 to position 5 using 2 moves.
- The third student is moved from from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.

Example 2:

Input: seats = [4,1,5,9], students = [1,3,2,6]
Output: 7
Explanation: The students are moved as follows:
- The first student is not moved.
- The second student is moved from from position 3 to position 4 using 1 move.
- The third student is moved from from position 2 to position 5 using 3 moves.
- The fourth student is moved from from position 6 to position 9 using 3 moves.
In total, 0 + 1 + 3 + 3 = 7 moves were used.

Example 3:

Input: seats = [2,2,6,6], students = [1,3,2,6]
Output: 4
Explanation: Note that there are two seats at position 2 and two seats at position 6.
The students are moved as follows:
- The first student is moved from from position 1 to position 2 using 1 move.
- The second student is moved from from position 3 to position 6 using 3 moves.
- The third student is not moved.
- The fourth student is not moved.
In total, 1 + 3 + 0 + 0 = 4 moves were used.

Constraints:

n == seats.length == students.length
1 <= n <= 100
1 <= seats[i], students[j] <= 100

*/

/*
************* Java Code **************

public int minMovesToSeat(int[] seats, int[] students) {
        int n = seats.length;
        Arrays.sort(seats);
        Arrays.sort(students);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += Math.abs(seats[i] - students[i]);
        }
        return res;
    }

public int minMovesToSeat(int[] seats, int[] students) {
        int n = seats.length;
        int[] seatsMap = new int[101];
        int[] studentMap = new int[101];
        for (int i = 0; i < n; i++)
        {
            seatsMap[seats[i]]++;
            studentMap[students[i]]++;
        }

        int i = 0, j = 0;
        int res = 0;
        while (i <= 100 && j <= 100)
        {
            if (seatsMap[i] == 0)
                i++;
            if (studentMap[j] == 0)
                j++;

            if (i <= 100 && j <= 100 && seatsMap[i] != 0 && studentMap[j] != 0)
            {
                res += Math.abs(i - j);
                seatsMap[i]--;
                studentMap[j]--;
            }
        }
        return res;
    }

*/