class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
        	return l2;
        if(!l2)
        	return l1;
        ListNode* emptyHead = new ListNode(0);
        ListNode* cur = emptyHead;
        while(l1 && l2)
        {
        	while(l1 && l2 && l1->val <= l2->val)
        	{
        		cur->next = l1;
        		cur = l1;
        		l1 = l1->next;
        	}
        	while(l1 && l2 && l1->val > l2->val)
        	{
        		cur->next = l2;
        		cur = l2;
        		l2 = l2->next;
        	}
        }
        if(!l1)
        	cur->next = l2;
        else
        	cur->next = l1;
        return emptyHead->next;
    }
};