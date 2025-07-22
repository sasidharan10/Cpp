#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // Brute
  int mostBooked2(int n, vector<vector<int>> &meetings)
  {
    // TC: O(m * n)
    // SC: O(n) + O(n)

    int m = meetings.size();
    sort(meetings.begin(), meetings.end());

    vector<int> roomsUsedCount(n, 0);
    vector<long long> lastAvailableAt(n, 0);
    for (int i = 0; i < m; i++)
    {
      int start = meetings[i][0];
      int end = meetings[i][1];
      int duration = end - start;
      bool found = false;

      int earlyEndRoom = 0;
      long long earlyEndRoomTime = LLONG_MAX;

      for (int room = 0; room < n; room++)
      {
        if (lastAvailableAt[room] <= start)
        {
          found = true;
          lastAvailableAt[room] = end;
          roomsUsedCount[room]++;
          break;
        }

        // finding the room with min end time
        if (lastAvailableAt[room] < earlyEndRoomTime)
        {
          earlyEndRoomTime = lastAvailableAt[room];
          earlyEndRoom = room;
        }
      }
      // if no room avaialbe, room with min end time will be used
      if (!found)
      {
        lastAvailableAt[earlyEndRoom] += duration;
        roomsUsedCount[earlyEndRoom]++;
      }
    }

    int maxUsedRoom = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
      if (roomsUsedCount[i] > maxi)
      {
        maxi = roomsUsedCount[i];
        maxUsedRoom = i;
      }
    }
    return maxUsedRoom;
  }

  // Optimal
  int mostBooked(int n, vector<vector<int>> &meetings)
  {
    // TC: O(m) * O(logn)
    // SC: O(n) + O(n)

    int m = meetings.size();
    sort(meetings.begin(), meetings.end());
    // min-heap
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms;
    priority_queue<int, vector<int>, greater<int>> availableRooms;
    vector<int> roomsUsedCount(n, 0);

    for (int i = 0; i < n; i++)
    {
      availableRooms.push(i);
    }

    for (int i = 0; i < m; i++)
    {
      int start = meetings[i][0];
      int end = meetings[i][1];
      // means the meeting ended, we can pop it
      while (!usedRooms.empty() && usedRooms.top().first <= start)
      {
        int room = usedRooms.top().second;
        usedRooms.pop();
        availableRooms.push(room);
      }
      // If free rooms available, we assign the current meeting
      if (!availableRooms.empty())
      {
        int room = availableRooms.top();
        availableRooms.pop();
        usedRooms.push({end, room});
        roomsUsedCount[room]++;
      }
      // Room with least endtime will have the next meeting
      else
      {
        int endTime = usedRooms.top().first;
        int room = usedRooms.top().second;
        usedRooms.pop();

        usedRooms.push({endTime + end - start, room});
        roomsUsedCount[room]++;
      }
    }

    int maxUsedRoom = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
      if (roomsUsedCount[i] > maxi)
      {
        maxi = roomsUsedCount[i];
        maxUsedRoom = i;
      }
    }
    return maxUsedRoom;
  }
};
int main()
{
  Solution s;
  int n = 3;
  vector<vector<int>> meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
  cout << "Room with Most meetings: " << s.mostBooked(n, meetings) << endl;
  return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/meeting-rooms-iii/

Youtube: https://www.youtube.com/watch?v=8JTr7Hk0p2o

algorithm:

- Brute Force Approach:

- We use 2 arrays, 1 to track the rooms used count and another, to
  check the time at which each room is available.
- We sort the meeting array, by starting time, since they should
  be picked based on their starting time.
- Now, traverse through each meetings time, and check if we can
  put in any available room slots.
- For wach meetings, we check each room from 0 - n, and check
  if the room is available or not.
- if (lastAvailableAt[room] <= start), means that meeting ends before the
  current meeting starts, hence we can use that room. We only keep the endtime
  in that array.
- Meanwhile, we also keep track of the room with least EndTime. So, if we dont
  find any room available, we know that the room with least endtime, will
  bw the room where we can have next meeting, hence we update its endtime,
  by adding the current meetings duration.
- Finally, we check for the room with max meetings, using the room count array.

- Optimal Approach:

- Here, instead for traversing through each room for finding available slots,
  we can keep 2 min-heaps, whcih  keep track of available rooms, and used rooms
  end time.
- So everytime we take a new meeting, we check if
  while (!usedRooms.empty() && usedRooms.top().first <= start), means
  endtime in that room will be over before the cuurent start time, so we
  can pop that from the heap (basically the meeting ended).
- case 2: checks if we have any free rooms, if yes, we can assign that room
  to current meeting.
- case 3: If no room available, we can pick the room with least endtime
  and add the duration to that meeting.

*/

/*

2402. Meeting Rooms III

You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi]
means that a meeting will be held during the half-closed time interval [starti, endi).
All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a
room becomes free. The delayed meeting should have the same duration
as the original meeting.
When a room becomes unused, meetings that have an earlier original
start time should be given the room.
Return the number of the room that held the most meetings. If there
are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b
including a and not including b.

Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts
  in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts \
  in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0.

Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts
  in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting
  starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1.

*/

/*
************* Java Code **************

  public static int mostBooked(int n, int[][] meetings) {
        int m = meetings.length;
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        // by default min-heap in java
        PriorityQueue<long[]> usedRooms = new PriorityQueue<>(
                (a, b) -> a[0] != b[0] ? Long.compare(a[0], b[0]) : Long.compare(a[1], b[1]));
        PriorityQueue<Integer> availableRooms = new PriorityQueue<>();
        int[] roomsUsedCount = new int[n];

        for (int i = 0; i < n; i++) {
            availableRooms.offer(i);
        }

        for (int i = 0; i < m; i++) {
            long start = meetings[i][0];
            long end = meetings[i][1];
            // means the meeting ended, we can pop it
            while (!usedRooms.isEmpty() && usedRooms.peek()[0] <= start) {
                int room = (int) usedRooms.peek()[1];
                usedRooms.poll();
                availableRooms.offer(room);
            }
            // If free rooms available, we assign the current meeting
            if (!availableRooms.isEmpty()) {
                int room = availableRooms.peek();
                availableRooms.poll();
                usedRooms.offer(new long[] { end, room });
                roomsUsedCount[room]++;
            }
            // Room with least endtime will have the next meeting
            else {
                long endTime = usedRooms.peek()[0];
                int room = (int) usedRooms.peek()[1];
                usedRooms.poll();

                usedRooms.offer(new long[] { endTime + end - start, room });
                roomsUsedCount[room]++;
            }
        }

        int maxUsedRoom = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (roomsUsedCount[i] > maxi) {
                maxi = roomsUsedCount[i];
                maxUsedRoom = i;
            }
        }
        return maxUsedRoom;
    }

*/