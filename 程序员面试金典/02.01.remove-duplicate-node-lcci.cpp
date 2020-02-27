class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
    	if(!head || !head->next)
    		return head;
    	unordered_set<int> s;
    	ListNode *prev = head, *cur = head->next;
    	s.insert(head->val);
    	while(cur)
    	{
    		if(!s.count(cur->val))
    		{
    			s.insert(cur->val);
    			prev = cur;
    			
    		}
    		else
    		{
    			prev->next = cur->next;
    		}
    		cur = cur->next;
    	}
    	return head;
    }
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
    	if(!head || !head->next)
    		return head;
    	ListNode *prev = head, *cur = head->next, *pc=NULL;
    	int v;
    	while(prev)
    	{
    		v = prev->val;
    		pc = prev;
    		cur = prev->next;
    		while(cur)
    		{
    			if(cur->val != v)
    			{
    				pc = cur;
    			}
    			else
    			{
    				pc->next = cur->next;
    			}
    			cur = cur->next;
    		}
    		prev = prev->next;
    	}
    	return head;
    }
};