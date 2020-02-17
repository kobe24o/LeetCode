class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        	return {};
        queue<TreeNode*> q;
        TreeNode *tp;
        q.push(root);
        stack<TreeNode*> s;
        int size;
        vector<int> lv;
        vector<vector<int>> ans;
        bool flag = false;
        while(!q.empty())
        {
        	size = q.size();
        	flag = !flag;
        	while(size--)
        	{
        		tp = q.front();
        		q.pop();
        		lv.push_back(tp->val);
        		if(flag)
        		{
        			if(tp->left)  s.push(tp->left);
        			if(tp->right) s.push(tp->right);
        		}
        		else
        		{
        			if(tp->right) s.push(tp->right);
        			if(tp->left)  s.push(tp->left);	
        		}
        	}
        	
    		while(!s.empty())
    		{
    			q.push(s.top());
    			s.pop();
    		}
        	ans.push_back(lv);
        	lv.clear();
        }
        return ans;
    }
};