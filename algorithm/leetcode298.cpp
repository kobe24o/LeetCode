class Solution {
	int maxlen = 1;
public:
    int longestConsecutive(TreeNode* root) {
    	if(!root) return 0;
    	dfs(root, 1);
    	return maxlen;
    }
    void dfs(TreeNode* root, int len)
    {
    	if(!root) return;
    	maxlen = max(maxlen, len);
    	if(root->left)
    	{
    		if(root->val+1 == root->left->val)
    			dfs(root->left, len+1);
    		else
    			dfs(root->left, 1);
    	}
    	if(root->right)
    	{
    		if(root->val+1 == root->right->val)
    			dfs(root->right, len+1);
    		else
    			dfs(root->right, 1);
    	}
    }
};