class Solution {
	int maxdiff = 0;
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val,root->val);
        return maxdiff;
    }

    void dfs(TreeNode* root, int MAX, int MIN) 
    {
    	if(!root)
    	{
    		maxdiff = max(maxdiff, abs(MAX-MIN));
    		return;
    	}
    	int MA = max(root->val, MAX);
    	int MI = min(root->val, MIN);
    	dfs(root->left,MA,MI);
    	dfs(root->right,MA,MI);
    }
};