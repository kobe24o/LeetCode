class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	ListNode *emptyHead = new ListNode(-1), *prev, *partTail;
    	emptyHead->next = head;
    	partTail = prev = emptyHead;
    	while(head)
    	{
    		if(head->val < x && partTail != prev)
    		{
    			prev->next = prev->next->next;
    			head->next = partTail->next;
    			partTail->next = head;
    			head = prev->next;
    		}
    		else
    		{
    			prev = head;
    			head = head->next;
    		}
    	}
    	return emptyHead->next;
    }
};