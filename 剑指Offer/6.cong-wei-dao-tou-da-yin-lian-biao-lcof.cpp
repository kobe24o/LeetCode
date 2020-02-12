class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        while(head)
        {
        	s.push(head->val);
        	head = head->next;
        }
        vector<int> ans;
        while(!s.empty())
        {
        	ans.push_back(s.top());
        	s.pop();
        }
        return ans;
    }
};

class Solution {
	vector<int> ans;
public:
    vector<int> reversePrint(ListNode* head) {
        dfs(head);
        return ans;
    }

    void dfs(ListNode* head)
    {
    	if(!head)
    		return;
    	dfs(head->next);
    	ans.push_back(head->val);
    }
};

class Solution {
	vector<int> ans;
public:
    vector<int> reversePrint(ListNode* head) {
    	if(!head)
    		return {};
        head = reverseList(head);
        while(head)
        {
        	ans.push_back(head->val);
        	head = head->next;
        }
        return ans;
    }

	ListNode* reverseList(ListNode* head)
	{
		ListNode *prev = NULL, *nt = head->next;
		while(head && head->next)
		{
			head->next = prev;
			prev = head;
			head = nt;
			nt = nt->next;
		}
		head->next = prev;
		return head;
	}    
};