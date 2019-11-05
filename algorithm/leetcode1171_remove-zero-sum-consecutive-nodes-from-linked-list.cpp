class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == NULL)
        	return NULL;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *prev = newHead, *cur = head, *temp;
        unordered_map<int,ListNode*> m;
        m[0] = prev;
        int sum = 0, s;
        unordered_map<int,ListNode*>::iterator it;
        while(cur != NULL)
        {
        	sum += cur->val;
        	it = m.find(sum);
        	if(it == m.end())
        		m[sum] = cur;
        	else
        	{
        		temp = it->second->next;
        		s = it->first + temp->val;
        		while(s != sum)
        		{
        			m.erase(s);
        			temp = temp->next;
        			s += temp->val;
        		}
        		it->second->next = cur->next;
        		sum = it->first;
        	}
        	cur = cur->next;
        }
        ListNode *ans = newHead->next;
        delete newHead;
        return ans;
    }
};