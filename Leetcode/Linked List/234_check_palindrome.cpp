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
    ListNode *ReverseList(ListNode *head)
    {
        ListNode *prev, *nextptr, *current;
        prev = NULL;
        current = head;
        if (head == NULL)
            return head;
        while (current != NULL)
        {
            nextptr = current->next;
            current->next = prev;
            prev = current;
            current = nextptr;
        }
        return prev;
    }
    // Better - by revering the half list, and checking both halfs, if they are same
    bool isPalindrome3(ListNode *head)
    {
        // TC: O(n) + O(n)
        // SC: O(1)

        ListNode *low = head;
        ListNode *high = head->next;
        while (high != NULL && high->next != NULL)
        {
            low = low->next;
            high = high->next->next;
        }
        ListNode *first = head;
        ListNode *second = low->next;
        low->next = NULL;
        second = ReverseList(second);
        print(first);
        print(second);
        while (first && second)
        {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }

    // Optimal - We reverse the half list, while finding the mid, then check both halfs
    bool isPalindrome2(ListNode *head)
    {
        // TC: O(n)
        // SC: O(1)

        ListNode *low = head;
        ListNode *high = head;
        ListNode *prev = nullptr;
        ListNode *nextNode = nullptr;
        while (high != NULL && high->next != NULL)
        {
            high = high->next->next;
            nextNode = low->next;
            low->next = prev;
            prev = low;
            low = nextNode;
        }

        // incase of odd elements, low will be pointing at the mid element if
        // high!= nullptr, hence we move 1 node further, to check with remaining elements
        if (high != nullptr)
            low = low->next;
        while (low && prev)
        {
            if (low->val != prev->val)
                return false;
            low = low->next;
            prev = prev->next;
        }
        return true;
    }

    // Optimal - Using recursion, we go till tail, then check the tail->val == front->val
    ListNode *front;   // global variable
    bool isPalindromeUtil(ListNode *tail)
    {
        bool res = true;
        if (tail->next)
            res = isPalindromeUtil(tail->next);
        res = res & (front->val == tail->val);
        front = front->next;
        return res;
    }
    bool isPalindrome(ListNode *head)
    {
        front = head;
        return isPalindromeUtil(head);
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 3);
    // head = s.InsertEnd(head, 3);
    s.print(head);
    cout << "Palindrome? : " << s.isPalindrome(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/palindrome-linked-list/description/

youtube: https://www.youtube.com/watch?v=Sgi2BHiW0-Q

*/

/*

234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

*/

/*

    public static ListNode front; // global variable

    public static boolean isPalindromeUtil(ListNode tail) {
        boolean res = true;
        if (tail.next != null)
            res = isPalindromeUtil(tail.next);
        res = res & (front.val == tail.val);
        front = front.next;
        return res;
    }

    public static boolean isPalindrome(ListNode head) {
        front = head;
        return isPalindromeUtil(head);
    }

*/