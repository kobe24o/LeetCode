class Solution {
	bool ans = true;
public:
    bool isSymmetric(TreeNode* root) {
        dfs(root,root);
        return ans;
    }

    void dfs(TreeNode* r1, TreeNode* r2)
    {
    	if(!ans || (!r1 && !r2))
    		return;
    	if((!r1 && r2)||(r1 && !r2))
    	{
    		ans = false;
    		return;
    	}
    	if(r1->val != r2->val)
    		ans = false;
    	dfs(r1->left,r2->right);
    	dfs(r1->right,r2->left);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        TreeNode *r1, *r2;
        while(!q.empty())
        {
        	r1 = q.front();	q.pop();
        	r2 = q.front();	q.pop();
        	if((!r1 && r2)||(r1 && !r2))
        		return false;
        	if(r1 && r2)
        	{
        		if(r1->val != r2->val)
        			return false;
        		q.push(r1->left);
        		q.push(r2->right);
        		q.push(r1->right);
        		q.push(r2->left);
        	}
        }
        return true;
    }
};