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
		if(k == 1 || !head)
			return head;
		int len = 1, count;
		ListNode *prev = NULL, *cur = head, *nt = head->next;
		cur = reverseList(prev,cur,nt,len);
		count = len/k;
		len = len%k;//反转后，前几个(原末尾)不用反转的
		prev = NULL, nt = cur->next;
		while(len--)
		{
			prev = cur;
			cur = cur->next;
			nt = cur->next;
		}
		if(prev)
			prev->next = NULL;
		ListNode *newhead;
		while(count--)
		{
			newhead = reverseKNode(cur,nt,k);//反转k个, cur是引用
			prev->next = newhead;
			prev = cur;
			cur = nt;
		}
		cur = prev, prev = NULL;
		return reverseList(prev,cur,nt,len);
    }

    ListNode* reverseList(ListNode *prev, ListNode *head, ListNode *nt, int& len)
    {
    	while(head && head->next)
		{
			len++;
			head->next = prev;
			prev = head;
			head = nt;
			nt = nt->next;
		}
		head->next = prev;
		return head;
    }

    ListNode* reverseKNode(ListNode* &head, ListNode* &nt, int k)
    {
    	ListNode *prev = NULL, *tail = head;
    	while(k--)
    	{
    		head->next = prev;
			prev = head;
			head = nt;
            if(nt)
			    nt = nt->next;
    	}
    	prev->next = NULL;
    	head = tail;
    	return prev;
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
    s.reverseKGroup(n1,2);
}