class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
        	return head;
        ListNode *emptyHead = new ListNode(0);
        emptyHead->next = head;
        ListNode *end = emptyHead, *prev = head, *cur = head->next;
        while(cur != NULL)
        {
        	if(prev->val != cur->val)
        	{
        		end->next = prev;
        		end = prev;
        	}
        	while(cur && prev->val == cur->val)
        	{
        		prev = cur;
        		cur = cur->next;
        	}
        	// end->next = cur;
        	// end = cur;
        	prev = prev->next;
        	if(cur)
        	cur = cur->next;
        }
        return emptyHead->next;
    }
};