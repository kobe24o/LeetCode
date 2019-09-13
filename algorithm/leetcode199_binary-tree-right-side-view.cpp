class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
        	return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        while(!q.empty())
        {
        	n = q.size();
        	ans.push_back(q.front()->val);
        	while(n--)
        	{
        		if(q.front()->right)
        			q.push(q.front()->right);
        		if(q.front()->left)
        			q.push(q.front()->left);
        		q.pop();
        	}
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }
    void dfs(TreeNode* root, vector<int> &ans, int level)
    {
    	if(root == NULL)
    		return;
    	if(ans.size() == level)
    		ans.push_back(root->val);
    	dfs(root->right, ans, level+1);
    	dfs(root->left, ans, level+1);
    }
};