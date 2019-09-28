class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
        	return true;
        ListNode *fast = head, *slow = head, *prev, *nextNode;
        while(fast && fast->next)
        {
        	fast = fast->next->next;
        	nextNode = slow->next;
        	slow->next = prev;
        	prev = slow;
        	slow = nextNode;
        }
        if(fast != NULL)//奇数个节点情况
        	slow = slow->next;
        while(slow)
        {
        	if(prev->val != slow->val)
        		return false;
        	prev = prev->next;
        	slow = slow->next;
        }
        return true;
    }
};