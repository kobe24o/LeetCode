/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	ListNode *emptyHead = new ListNode(-1), *prev, *partTail;
    	emptyHead->next = head;
    	partTail = prev = emptyHead;
    	while(head)
    	{
    		if(head->val < x && partTail != prev)
    		{
    			prev->next = prev->next->next;
    			head->next = partTail->next;
    			partTail->next = head;
    			head = prev->next;
    		}
    		else
    		{
    			prev = head;
    			head = head->next;
    		}
    	}
    	return emptyHead->next;
    }
};

int main()
{
    Solution s;
    ListNode *h1 = new ListNode(3);
    ListNode *h2 = new ListNode(5);
    ListNode *h3 = new ListNode(8);
    ListNode *h4 = new ListNode(5);
    ListNode *h5 = new ListNode(10);
    ListNode *h6 = new ListNode(2);
    ListNode *h7 = new ListNode(1);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    s.partition(h1,5);
     return 0;
}