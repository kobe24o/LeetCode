class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
        	return NULL;
        ListNode *cur = headA;
        int lenA = 0, lenB = 0, delta;
        while(cur)
        {
        	++lenA;
        	cur = cur->next;
        }
        cur = headB;
        while(cur)
        {
        	++lenB;
        	cur = cur->next;
        }
        if(lenA > lenB)
        {
        	delta = lenA - lenB;
        	while(delta--)
        		headA = headA->next;
        }
        else
        {
        	delta = lenB - lenA;
        	while(delta--)
        		headB = headB->next;
        }
        while(headA != headB)
        {
        	headA = headA->next;
        	headB = headB->next;
        }
        return headA;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ha = headA, *hb = headB;
        while(ha != hb)
        {
            ha = ha? ha->next : headB;
            hb = hb ? hb->next : headA;
        }
        return ha;
    }
};