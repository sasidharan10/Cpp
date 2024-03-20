#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *InsertEnd(ListNode *head, int n)
    {
        ListNode *temp1 = new ListNode(n);
        if (head == NULL)
        {
            head = temp1;
            return head;
        }
        ListNode *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
        return head;
    }
    void print(ListNode *p)
    {

        cout << "List: ";
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        // TC: O(n + m)
        // SC: O(1)
        
        ListNode *dummy = new ListNode(0);
        dummy->next = list1;
        ListNode *start = dummy, *end, *prevEnd;
        for (int i = 0; i < a; i++)
        {
            start = start->next;
        }
        prevEnd = start;
        for (int i = 0; i < b - a + 1; i++)
        {
            prevEnd = prevEnd->next;
        }
        end = prevEnd->next;
        ListNode *list2End = list2;
        while (list2End->next)
        {
            list2End = list2End->next;
        }

        prevEnd->next = nullptr;   // breaking the end of 'b' link
        start->next = list2;       // linking 'a' to list2
        list2End->next = end;      // linking list2's end with 'b';
        return dummy->next;
    }
};
int main()
{
    Solution s;
    ListNode *list1 = nullptr;
    list1 = s.InsertEnd(list1, 0);
    list1 = s.InsertEnd(list1, 1);
    list1 = s.InsertEnd(list1, 2);
    list1 = s.InsertEnd(list1, 3);
    list1 = s.InsertEnd(list1, 4);
    list1 = s.InsertEnd(list1, 5);
    list1 = s.InsertEnd(list1, 6);

    ListNode *list2 = nullptr;
    list2 = s.InsertEnd(list2, 1000000);
    list2 = s.InsertEnd(list2, 1000001);
    list2 = s.InsertEnd(list2, 1000002);
    list2 = s.InsertEnd(list2, 1000003);
    list2 = s.InsertEnd(list2, 1000004);
    int a = 2, b = 5;
    s.print(list1);
    s.print(list2);
    list1 = s.mergeInBetween(list1, a, b, list2);
    cout << "List After merging List2: " << endl;
    s.print(list1);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/merge-in-between-linked-lists/

Youtube: https://www.youtube.com/watch?v=wIC9enD8Wzg

algorithm:

Code Link:

- Optimal Approach:

-

*/

/*






*/

/*
************* Java Code **************

public static ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode dummy = new ListNode(0);
        dummy.next = list1;
        ListNode start = dummy, end, prevEnd;
        for (int i = 0; i < a; i++) {
            start = start.next;
        }
        prevEnd = start;
        for (int i = 0; i < b - a + 1; i++) {
            prevEnd = prevEnd.next;
        }
        end = prevEnd.next;
        ListNode list2End = list2;
        while (list2End.next != null) {
            list2End = list2End.next;
        }
        
        prevEnd.next = null;   // breaking the end of 'b' link
        start.next = list2;    // linking 'a' to list2
        list2End.next = end;   // linking list2's end with 'b';
        return dummy.next;
    }

*/