#include <bits/stdc++.h>
using namespace std;

// Better
class SeatManager2
{
    // TC: O(nlogn)
    // SC: O(n)

    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager2(int n)
    {
        // O(nlogn)
        for (int i = 1; i <= n; i++)
        {
            availableSeats.push(i);
        }
    }

    int reserve()
    {
        // O(logN)
        int seat = availableSeats.top();
        availableSeats.pop();
        return seat;
    }

    void unreserve(int seatNumber)
    {
        // O(logN)
        availableSeats.push(seatNumber);
    }
};


// Optimal
class SeatManager1
{
    // TC: O(nlogn)
    // SC: O(n)

    priority_queue<int, vector<int>, greater<int>> availableSeats;
    int seatMarker;
public:
    SeatManager1(int n)
    {
        // O(1)
        seatMarker = 1;
    }

    int reserve()
    {
        // O(logN)
        if (!availableSeats.empty())
        {
            int seat = availableSeats.top();
            availableSeats.pop();
            return seat;
        }
        // O(1)
        else
        {
            int seat = seatMarker;
            seatMarker++;
            return seat;
        }
    }

    void unreserve(int seatNumber)
    {
        // O(logN)
        availableSeats.push(seatNumber);
    }
};

// My Approach (also near Optimal)
class SeatManager
{
    // TC: O(nLogN)  // My approach
    // SC: O(2n)
    
    vector<bool> seat;
    priority_queue<int, vector<int>, greater<int>> q;
    int ptr;

public:
    SeatManager(int n)
    {
        // O(1)
        seat.resize(n, false);
        ptr = 0;
    }

    int reserve()
    {
        // O(1)
        if (q.empty())
        {
            seat[ptr] = true;
            ++ptr;
            return ptr;
        }
        // O(logN)
        else
        {
            int i = q.top();
            q.pop();
            seat[i] = true;
            return i + 1;
        }
    }

    void unreserve(int seatNumber)
    {
        // O(logN)
        q.push(seatNumber - 1);
        seat[seatNumber - 1] = false;
    }
};
class Solution
{
public:
};
int main()
{
    Solution s;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

- Since, the maximum seats can be 10^5 and the maximum number of reserve/unreserve call
can also be 10^5, so we can not use vector/array to track these values, it'll give us TLE.
- It will always have it's smallest value on top, so if we have considered our min heap as
 unreserved list, then we can simply remove the top value for reserve() call
*/