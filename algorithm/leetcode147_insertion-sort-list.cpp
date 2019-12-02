class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
        	return head;
        ListNode *emptyHead = new ListNode(0);
        emptyHead->next = head;
       	multimap<int, ListNode*> m;
       	while(head)
       	{
       		m.emplace(head->val, head);
       		head = head->next;
       	}
       	head = emptyHead;
       	for(auto & kv : m)
       	{
   			head->next = kv.second;
   			head = head->next;   		
       	}
       	head->next = NULL;
       	return emptyHead->next;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
        	return head;
        ListNode *emptyHead = new ListNode(0);
        emptyHead->next = head;
       	ListNode *cur = head->next, *tail = head, *nt = NULL, *t, *prev;
       	while(cur)
       	{
       		nt = cur->next;
       		if(cur->val >= tail->val)
       		{
       			tail->next = cur;
       			tail = cur;
       		}
       		else
       		{
       			prev = emptyHead;
       			t = emptyHead->next;
       			while(cur->val > t->val)
       			{
       				prev = t;
       				t = t->next;
       			}
       			prev->next = cur;
       			cur->next = t;
       		}
       		cur = nt;
       	}
       	tail->next = NULL;
       	return emptyHead->next;
    }
};