/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
int val;
 ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *emptyHead = new ListNode(-1);
        emptyHead->next = head;
        ListNode *prev = emptyHead, *start = emptyHead->next, *end = emptyHead;
        ListNode *temp=NULL;
        bool flag = false;
        int count;
        while(end)
        {
            count = k;
            start = prev->next;
            while(end && count)
            {
                end = end->next;
                count--;
            }
            if(!end)//
                flag = true;//这一段不足k个，提前结束了,allEnd是结尾
            else
            {
                temp = end->next;
                end->next = NULL;
            }
            if(!flag)
            {
                prev->next = reverseList(start);
                start->next = temp;
                prev = start;
                end = start;
            }
        }
        return emptyHead->next;
    }

    ListNode* reverseList(ListNode *head)
    {
        ListNode *prev = NULL, *nt = head->next;
        while(head && head->next)
        {
            head->next = prev;
            prev = head;
            head = nt;
            if(nt)
                nt = nt->next;
        }
        head->next = prev;
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    cout <<  s.reverseKGroup(n1,2);
    cout << " ";
}