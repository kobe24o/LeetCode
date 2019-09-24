class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        	return head;
        ListNode *fast = head->next, *slow = head, *rightHead;
        //fast初始化先走一步，偶数个链表时，防止一边0个，一边2个节点
        while(fast && fast->next)
        {
        	fast = fast->next->next;
        	slow = slow->next;
        }
        rightHead = slow->next;
        slow->next = NULL;//先断开，再操作左右！！！
        ListNode *right = sortList(rightHead);
        ListNode *left = sortList(head);
        return merge(left, right);
    }
    ListNode* merge(ListNode *left, ListNode *right) 
    {
    	ListNode *emptyHead = new ListNode(0);//虚拟哨兵头
    	ListNode *cur = emptyHead;
    	while(left && right)
    	{
    		if(left->val < right->val)
    		{
    			cur->next = left;
    			left = left->next;
    		}
    		else
    		{
    			cur->next = right;
    			right = right->next;
    		}
    		cur = cur->next;
    	}
    	cur->next = (left == NULL ? right : left);
    	cur = emptyHead->next;
    	delete emptyHead;
    	return cur;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode *head) {
        quicksort(head, NULL);
        return head;
    }
    void quicksort(ListNode *head, ListNode *tail) 
    {
    	if(head == NULL || head->next == NULL)
        	return;
    	ListNode *left = head, *pivot = head, *cur = head->next;
    	while(cur != tail)
    	{
    		if(cur->val < pivot->val)
    		{
    			swap(cur->val, pivot->val);
    			pivot = cur;
    		}
    		cur = cur->next;
    	}
    	quicksort(head, pivot);
    	quicksort(pivot->next, tail);
    }
};