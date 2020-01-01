class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> stk;
        stack<int> idx;
        int n = 0;
        for( ; head; head=head->next)
        {
        	i = 0;
        	while(!stk.empty() && stk.top() < head->val)
        	{
        		i++;//计数
        		stk.pop();
        		ans[idx.top()] = head->val;
        		idx.pop();
        	}
        	stk.push(head->val);
        	idx.push(n++);
        	ans.push_back(0);
        }
        return ans;
    }
};