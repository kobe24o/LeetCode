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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *cur = list1, *cur2 = list1->next;
        ListNode *tail2 = list2;
        b -= a;
        while(tail2->next)
            tail2 = tail2->next;//链表2的尾节点
        while(--a)
        {
            cur = cur->next;
        }
        cur2 = cur->next;//要删除的部分的开始
        cur->next = list2;//接上链表2
        while(b--)//链表1剩余要删除的部分，遍历
        {
            cur2 = cur2->next;
        }
        tail2->next = cur2->next;//链表2的尾巴接上要删除的部分的尾巴的下一个
        return list1;
    }
};
