class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *emptyHead = new ListNode(-1);
        emptyHead->next = head;
        ListNode *prev = emptyHead;
        while(head && head->val != val)
        {
        	prev = head;
        	head = head->next;
        }
        prev->next = head->next;
        return emptyHead->next;
    }
};