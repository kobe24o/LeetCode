/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
	struct cmp
    {
    	bool operator()(ListNode *a, ListNode *b)
    	{
    		return a->val > b->val;
    	}
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> queue;
        for(int i = 0; i < k; ++i)
        {
        	queue.push_back(lists[i]);
        }
        while(!queue.empty())
        {
        	
        }
    }
};