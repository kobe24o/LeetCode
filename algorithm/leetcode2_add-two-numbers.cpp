/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int sum, one = 0;
        ListNode *nextNode = NULL;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL && l2 != NULL)
            {
                sum = l1->val + l2->val + one;
                one = sum/10;
                ListNode *newNode = new ListNode(sum%10);
                newNode->next = nextNode;
                nextNode = newNode;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 != NULL && l2 == NULL)
            {
                sum = l1->val + one;
                one = sum/10;
                ListNode *newNode = new ListNode(sum%10);
                newNode->next = nextNode;
                nextNode = newNode;
                l1 = l1->next;
            }
            else
            {
                sum = l2->val + one;
                one = sum/10;
                ListNode *newNode = new ListNode(sum%10);
                newNode->next = nextNode;
                nextNode = newNode;
                l2 = l2->next;
            }
        }
        if(one != 0)
        {
            ListNode *newNode = new ListNode(1);
            newNode->next = nextNode;
            nextNode = newNode;
        }
        return reverseList(nextNode);
    }

    ListNode* reverseList(ListNode *cur)
    {
        if(cur->next == NULL)
            return cur;
        ListNode *prevNode = NULL, *nextNode = cur->next;
        while(cur != NULL && cur->next != NULL)
        {
            cur->next = prevNode;
            prevNode = cur;
            cur = nextNode;
            nextNode = nextNode->next;
        }
        cur->next = prevNode;
        return cur;//反转链表后的新的头结点
    }
};