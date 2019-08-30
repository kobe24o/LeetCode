/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ha = headA, *hb = headB;
        int lena = 0, lenb = 0;
        while(ha)
        {
        	++lena;
        	ha = ha->next;
        }
        while(hb)
        {
        	++lenb;
        	hb = hb->next;
        }
        int t = abs(lena - lenb);
        hb = headB;
		ha = headA;
        if(lenb >= lena)
        {
        	while(t--)
        		hb = hb->next;
        }
        else//(lenb < lena)
        {
        	while(t--)
				ha = ha->next;       	
        }
        while(ha&&(ha!=hb))
    	{
    		ha = ha->next;
    		hb = hb->next;
    	}
    	return ha;
	}
};