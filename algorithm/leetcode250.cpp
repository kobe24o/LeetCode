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
    	bool l = dfs(root->left);
    	bool r = dfs(root->right);
    	if((!root->left && !root->right) 
    		||(root->left && !root->right && root->val == root->left->val)
    		||(!root->left && root->right && root->val == root->right->val)
    		||(root->left && root->right && root->val == root->left->val && root->val == root->right->val))
		{
			count++;
			return true;
		}    		
		return false;
    }
};