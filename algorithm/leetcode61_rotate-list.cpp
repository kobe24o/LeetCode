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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head ||!head->next)
            return head;
        int len = 0;
        ListNode *tmp = head;
        while(tmp)
        {
            ++len;
            tmp = tmp->next;
        }
        k = k%len;
        if(k == 0)
            return head;
        tmp = head;
        int count = len-k-1;
        while(count--)
        {
            
        }
    }
};