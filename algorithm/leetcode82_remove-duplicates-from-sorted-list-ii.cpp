class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
        	return head;
        ListNode *emptyHead = new ListNode(0);
        emptyHead->next = head;
        int count = 1;
        ListNode *end = emptyHead, *prev = head, *cur = head->next;
        while(cur != NULL)
        {
        	if(prev->val != cur->val)
        	{
                if(count == 1)
        		{
                    end->next = prev;
                    end = prev;
                }
                count = 1;
        	}
        	else
                count++;

            prev = cur;
            cur = cur->next;
        }
        if(count == 1)
            end->next = prev;
        else
            end->next = NULL;
        return emptyHead->next;
    }
};