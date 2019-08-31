/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prevNode = NULL, *nextNode;
        while(head)
        {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
    }
};