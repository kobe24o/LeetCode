/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur = head, *prev = head;
        ListNode* a, *b;
        int n = k-1;
        while(n--)
        {
            cur = cur->next;
        }
        a = cur;
        while(cur->next != NULL)
        {
            cur = cur->next;
            prev = prev->next;
        }
        b = prev;
        swap(a->val, b->val);
        return head;
    }
};