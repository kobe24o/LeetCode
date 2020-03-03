class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(!l1)
    		return l2;
    	if(!l2)
    		return l1;
    	int carry = 0, bit, sum;
    	ListNode *prev = NULL, *newNode, *head = l1;
    	while(l1 || l2 || carry)
    	{
    		sum = (l1 ? l1->val : 0)+(l2 ? l2->val : 0)+carry;
    		bit = sum%10;
    		carry = sum/10;
    		if(l1)
            {
                l1->val = bit;
                prev = l1;
                l1 = l1->next;
            }   
    		else
    		{
    			newNode = new ListNode(bit);
    			prev->next = newNode;
    			prev = prev->next;
    		}
            if(l2)
    		    l2 = l2->next;
    	}
    	return head;
    }
};