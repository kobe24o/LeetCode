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
//    Solution s;
    multimap<int,int> m;
    m.insert(make_pair(0,1));
//    m.insert(make_pair(0,1));
    cout << m.size();
}