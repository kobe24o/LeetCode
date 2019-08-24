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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        else
        {
            ListNode *newHead = new ListNode(0);
            ListNode *curNode = newHead->next, *prev = newHead;
            while(l1 && l2)
            {
                if(l1->val < l2->val)
                {
                    curNode = l1;
                    l1 = l1->next;
                }
                else
                {
                    curNode = l2;
                    l2 = l2->next;
                }
                prev->next = curNode;
                prev = curNode;
                curNode = curNode->next;

            }
            if(l1 == NULL)
            {
                while(l2)
                {
                    curNode = l2;
                    l2 = l2->next;
                    prev->next = curNode;
                    prev = curNode;
                    curNode = curNode->next;    
                }
            }
            else//l2 == NULL
            {
                while(l1)
                {
                    curNode = l1;
                    l1 = l1->next;
                    prev->next = curNode;
                    prev = curNode;
                    curNode = curNode->next;
                }
            }
            return newHead->next;
        }        
    }
};