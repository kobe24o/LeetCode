/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode *prevNode = NULL, *nextNode;
//        while(head)
//        {
//            nextNode = head->next;
//            head->next = prevNode;
//            prevNode = head;
//            head = nextNode;
//        }
//        return prevNode;
//    }
//};

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *p = reverseList(head->next);
    head->next->next = head;//p->next = head;错误写法
    head->next = NULL;
    return p;
    }
};
int main()
{
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b, b.next = &c, c.next = &d, d.next = &e;
    Solution s;
    s.reverseList(&a);
}