class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode *emptyHead = new ListNode(-1);
    	emptyHead->next = head;
        ListNode *cur = head, *prev = emptyHead;
        while(cur != NULL)
        {
        	if(cur->val == val)
        	{
        		prev->next = cur->next;
        		cur = prev->next;
        	}
        	else
        	{
        		cur = cur->next;
        		prev = prev->next;
        	}
        }
        return emptyHead->next;
    }
};