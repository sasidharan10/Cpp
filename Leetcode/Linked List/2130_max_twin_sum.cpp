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
    int pairSum(ListNode *head)
    {
        int sum = 0, maxSum = 0;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        ListNode *first = head;
        ListNode *second = slow->next;
        slow->next = nullptr;
        second = reverseList(second);
        while (first)
        {
            sum = first->val + second->val;
            maxSum = max(sum, maxSum);
            first = first->next;
            second = second->next;
        }
        return maxSum;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 7);
    head = s.InsertEnd(head, 3);
    s.print(head);
    cout << "Max twin sum: " << s.pairSum(head) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

*/