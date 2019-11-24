class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
        	return head;
        ListNode *emptyHead = new ListNode(0), *prev = emptyHead;
        emptyHead->next = head;//哨兵头节点，方便处理边界
        while(head && head->val < x)
        {
        	prev = head;
        	head = head->next;
        }
        if(!head)//全部小于x
        	return emptyHead->next;
        ListNode *greatHead = head, *greatEnd = head, *smallEnd = prev;
        ListNode *cur = head->next;
        greatEnd->next = NULL;
        while(cur)
        {
        	while(cur && cur->val >= x)
        	{
        		greatEnd->next = cur;
        		greatEnd = cur;
        		// p = cur;
        		cur = cur->next;
        	}
        	if(cur)//cur存在，其val小于x
        	{
        		// greatEnd = p;
        		greatEnd->next = NULL;
        		smallEnd->next = cur;
        		smallEnd = cur;
        		cur = cur->next;
        	}
        }
        smallEnd->next = greatHead;
        return emptyHead->next;
    }
};