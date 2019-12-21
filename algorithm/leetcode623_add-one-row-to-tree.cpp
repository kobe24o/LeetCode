class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
        {
        	TreeNode *newRoot = new TreeNode(v);
        	newRoot->left = root;
        	return newRoot;
        }
        int deep = 1, n;
        queue<TreeNode*> q;
        TreeNode *tp, *l, *r;
        q.push(root);
        while(!q.empty() && deep < d)
        {
        	n = q.size();
        	while(n--)
        	{
	        	tp = q.front();
    	    	q.pop();
    	    	if(deep == d-1)
    	    	{
    	    		l = tp->left;
    	    		r= tp->right;
    	    		tp->left = new TreeNode(v);
    	    		tp->right = new TreeNode(v);
    	    		tp->left->left = l;
    	    		tp->right->right = r;
    	    	}
    	    	if(tp->left)
    	    		q.push(tp->left);
    	    	if(tp->right)
    	    		q.push(tp->right);
    	    }
    	    deep++;
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
        {
        	TreeNode *newRoot = new TreeNode(v);
        	newRoot->left = root;
        	return newRoot;
        }
        dfs(root,1,d,v);
        return root;
    }

    void dfs(TreeNode* root, int deep, int &d, int &v)
    {
    	if(!root || deep == d)
    		return;
    	if(deep == d-1)
    	{
    		TreeNode* l = root->left;
    		TreeNode* r = root->right;
    		root->left = new TreeNode(v);
    		root->right = new TreeNode(v);
    		root->left->left = l;
    		root->right->right = r;
    	}
    	dfs(root->left,deep+1,d,v);
    	dfs(root->right,deep+1,d,v);
    }
};