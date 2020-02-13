class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(!head)
    		return head;
        ListNode *prev = NULL, *nt = head->next;
        while(head && head->next)
        {
        	head->next = prev;
        	prev = head;
        	head = nt;
        	nt = nt->next;
        }
        head->next = prev;
        return head;
    }
};

class Solution {
    ListNode *newhead;
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *nt = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nt;
    }
};