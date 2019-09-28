class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(n == 0)
    		return head;
        ListNode *gofirst = head, *behind = head;
        while (n--)
        	gofirst = gofirst->next;
        if(gofirst == NULL)//说明删除的是头
        {
        	return behind->next;
        }
        else
        {
	        while(gofirst->next != NULL)
	        {
	        	gofirst = gofirst->next;
	        	behind = behind->next;
	        }
	        behind->next = behind->next->next;
	        return head;
	    }
    }
};