class Solution {
	int count = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
    	dfs(root);
    	return count;
    }
    bool dfs(TreeNode* root)
    {
    	if(!root) return true;
    	bool l = dfs(root->left);//左子树都一样吗？
    	bool r = dfs(root->right);
    	if(!l || !r || (root->left && root->val != root->left->val) 
    		||(root->right && root->val != root->right->val))		
		    return false;
        count++;
		return true;
    }
};