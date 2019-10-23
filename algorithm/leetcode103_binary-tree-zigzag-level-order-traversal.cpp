class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
        	return {};
        queue<TreeNode*> q;
        TreeNode *tp;
        q.push(root);
        vector<int> lv;
        vector<vector<int>> ans;
        int n, depth = 0;
        while(!q.empty())
        {
        	n = q.size();
        	while(n--)
        	{
        		tp = q.front();
        		q.pop();
        		lv.push_back(tp->val);     	
    			if(tp->left)
    				q.push(tp->left);
    			if(tp->right)
    				q.push(tp->right);
        	}
        	depth++;
        	if(depth%2 == 0)
        		reverse(lv.begin(),lv.end());
        	ans.push_back(lv);
        	lv.clear();
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
        	return {};
        stack<TreeNode*> l, r;
        TreeNode *tp;
        l.push(root);
        vector<int> lv;
        vector<vector<int>> ans;
        while(!l.empty() || !r.empty())
        {
        	while(!l.empty())
        	{
        		tp = l.top();
        		l.pop();
        		lv.push_back(tp->val);     	
    			if(tp->left)
    				r.push(tp->left);
    			if(tp->right)
    				r.push(tp->right);
        	}
        	if(!lv.empty())
        	{
        		ans.push_back(lv);
        		lv.clear();
        	}

        	while(!r.empty())
        	{
        		tp = r.top();
        		r.pop();
        		lv.push_back(tp->val);
        		if(tp->right)
    				l.push(tp->right);
        		if(tp->left)
    				l.push(tp->left);  			
        	}
        	if(!lv.empty())
        	{
        		ans.push_back(lv);
        		lv.clear();
        	}	
        }
        return ans;
    }
};