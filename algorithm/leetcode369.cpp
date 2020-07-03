class Solution {
public:
    ListNode* plusOne(ListNode* head) {
    	int carry = 1;
    	dfs(head, carry);
    	if(carry)
    	{
    		ListNode* newhead = new ListNode(carry);
    		newhead->next = head;
    		return newhead;
    	}
    	return head;
    }
    void dfs(ListNode* head, int& carry)
    {
    	if(!head) return;
    	dfs(head->next, carry);
    	int sum = head->val+carry;
    	head->val = sum%10;
    	carry = sum/10;
    }
};