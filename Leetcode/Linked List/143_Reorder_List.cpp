#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
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
    void printList(ListNode *head)
    {
        cout << "List: ";
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *nextNode = nullptr;
        while (current)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
        return head;
    }

    // Optimal - reverse the 2nd half, and merge with the first half.
    void reorderList(ListNode *head)
    {
        // T.C : O(n)
        // S.C : O(1) Auxiliary, O(n) Recursion stack space

        ListNode *l1 = head;
        ListNode *l2 = nullptr;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }

        l2 = slow->next;
        slow->next = nullptr;
        l2 = reverseList(l2);
        // printList(l1);
        // printList(l2);
        ListNode *temp1 = nullptr;
        ListNode *temp2 = nullptr;
        while (l2)
        {
            // take smaller list, to avoid "out of bound error"
            temp1 = l1->next;
            temp2 = l2->next;

            l1->next = l2;
            l2->next = temp1;
            l2 = temp2;
            l1 = temp1;
        }
    }
    ListNode *front;
    void solve(ListNode *tail)
    {
        if (!tail)
            return;
        solve(tail->next);

        ListNode *nextFront = front->next;
        // it means our reorder is completed
        if (!nextFront)
            return;
        // it means both front and tail end up at the mid node. hence assign null and return.
        else if (front == tail)
        {
            front->next = nullptr;
            return;
        }

        front->next = tail;
        // if front and tail are adjacent nodes, then cycle will be formed, hence we assign it as null.
        tail->next = (nextFront == tail) ? nullptr : nextFront;
        front = nextFront;
    }
    void reorderList2(ListNode *head)
    {
        front = head;
        solve(front);
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 5);
    s.printList(head);
    s.reorderList2(head);
    s.printList(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reorder-list/description/

youtube: https://www.youtube.com/watch?v=7cp_HR1BT1E

*/


/*

    public static ListNode front; // global variable

    public static void solve(ListNode tail) {
        if (tail == null)
            return;
        solve(tail.next);

        ListNode nextFront = front.next;
        // it means our reorder is completed
        if (nextFront == null)
            return;
        // it means both front and tail end up at the mid node. hence assign null and
        // return.
        else if (front == tail) {
            front.next = null;
            return;
        }

        front.next = tail;
        // if front and tail are adjacent nodes, then cycle will be formed, hence we
        // assign it as null.
        tail.next = (nextFront == tail) ? null : nextFront;
        front = nextFront;
    }

    public static void reorderList(ListNode head) {
        front = head;
        solve(front);
    }

*/