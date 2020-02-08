class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		if(k == 1 || !head)
			return head;
		int len = 1, count;
		ListNode *prev = NULL, *cur = head, *nt = head->next;
		cur = reverseList(prev,cur,nt,len);
		count = len/k;
		len = len%k;//反转后，前几个(原末尾)不用反转的
		prev = NULL, nt = cur->next;
		while(len--)
		{
			prev = cur;
			cur = cur->next;
			nt = cur->next;
		}
		ListNode *tail;
		while(count--)
		{
			prev->next = NULL;
			tail = reverseKNode(cur,k);//反转k个, cur是引用
			
		}
    }

    ListNode* reverseList(ListNode *prev, ListNode *head, ListNode *nt, int& len)
    {
    	while(head && head->next)
		{
			len++;
			head->next = prev;
			prev = head;
			head = nt;
			nt = nt->next;
		}
		head->next = prev;
		return head;
    }

    void reverseKNode(ListNode)
};