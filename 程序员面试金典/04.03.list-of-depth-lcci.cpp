class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
    	if(!tree)
    		return {};
    	queue<TreeNode*> q;
    	vector<ListNode*> ans;
    	q.push(tree);
    	int size;
    	TreeNode* tp;
    	ListNode* head, *cur;
    	bool hashead;
    	while(!q.empty())
    	{
    		size = q.size();
    		hashead = false;
    		while(size--)
    		{
    			tp = q.front();
    			q.pop();
    			if(!hashead)
    			{
    				head = new ListNode(tp->val);
    				cur = head;
    				hashead = true;
    			}
    			else
    			{
    				cur->next = new ListNode(tp->val);
    				cur = cur->next;
    			}
    			if(tp->left)
    				q.push(tp->left);
    			if(tp->right)
    				q.push(tp->right);
    		}
    		ans.push_back(head);
    	}
    	return ans;
    }
};