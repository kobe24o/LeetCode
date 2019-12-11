class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=0, n2=0, sum = 0;
        while(l1)
        {
        	n1 = n1*10+l1->val;
        	l1 = l1->next;
        }
        while(l2)
        {
        	n2 = n2*10+l2->val;
        	l2 = l2->next;
        }
        sum = n1+n2;
        ListNode *head = NULL;
        while(sum)
        {
        	ListNode *node = new ListNode(sum%10);
        	node->next = head;
        	head = node;
        	sum /= 10;
        }
        return head;
    }
};