class Solution {
	vector<int> v;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        while(head)
        {
        	v.push_back(head->val);
        	head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

class Solution {
	ListNode *H;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) { H = head; }
    
    /** Returns a random node's value. */
    int getRandom() {
    	int count = 0, i;
        ListNode *select, *h = H;
        while(h)
        {
        	if(count++ == 0)
            	select = h;
        	else
        	{
        		i = rand()%count;
        		if(i < 1)//0, 概率1/count
        			select = h;
        	}
        	h = h->next;
        }
        return select->val;
    }
};