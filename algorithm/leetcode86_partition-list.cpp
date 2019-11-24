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
        //不全部小于x，head处是大于等于x的
        ListNode *greatHead = head, *greatEnd = head, *smallEnd = prev;
        ListNode *cur = head->next;
        greatEnd->next = NULL;//之前没写，链表只有2个节点，出错
        while(cur)
        {
        	while(cur && cur->val >= x)//跳过都是大于等于的
        	{
        		greatEnd->next = cur;
        		greatEnd = cur;
        		cur = cur->next;
        	}
        	if(cur)//cur存在，其val小于x
        	{
        		greatEnd->next = NULL;//断开大的尾部
        		smallEnd->next = cur;//接上small段
        		smallEnd = cur;
        		cur = cur->next;
        	}
        }
        smallEnd->next = greatHead;//最后把小于x的后面接上后面的
        return emptyHead->next;
    }
};