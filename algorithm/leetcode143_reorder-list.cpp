class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
        	return;
        ListNode *fast = head, *slow = head, *cur = head, *h, *nt;
        while(fast && fast->next)
        {
        	fast = fast->next->next;
        	slow = slow->next;
        }
        h = slow->next;
        slow->next = NULL;
        h = revList(h);
        while(h)
        {
        	nt = cur->next;
        	cur->next = h;
            h = h->next;
        	cur->next->next = nt;
        	cur = nt;
        }
    }

    ListNode* revList(ListNode* head)
    {
    	if(!head || !head->next)
    		return head;
    	ListNode *prev=NULL, *cur=head, *nt = head->next;
    	while(cur)
    	{
    		cur->next = prev;
    		prev = cur;
    		cur = nt;
    		if(nt)
    			nt = nt->next;
    	}
    	return prev;
    }
};