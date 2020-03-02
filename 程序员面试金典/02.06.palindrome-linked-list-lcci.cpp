class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(!head || !head->next)
    		return true;
    	ListNode *halfhead = NULL, *fast = head->next, *slow = head;
    	while(fast && fast->next)
    	{
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	halfhead = slow->next;
    	slow->next = NULL;
    	halfhead = reverseList(halfhead);
    	while(head && halfhead)
    	{
    		if(head->val != halfhead->val)
    			return false;
            head = head->next;
            halfhead = halfhead->next;
    	}
    	return true;
    }

    ListNode* reverseList(ListNode *head)
    {
    	ListNode *prev = NULL, *cur = head, *nt = cur->next;
    	while(cur && cur->next)
    	{
    		cur->next = prev;
    		prev = cur;
    		cur = nt;
    		nt = nt->next;
    	}
    	cur->next = prev;
    	return cur;
    }
};