class Solution {
	int sum = 0;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return sum;
    }

    void dfs(TreeNode* root, int cursum)
    {
    	if(root == NULL)
    		return;
    	if(!root->left && !root->right)
    	{
    		sum += cursum*10+root->val;
    		return;
    	}
    	dfs(root->left, cursum*10+root->val);
    	dfs(root->right, cursum*10+root->val);
    }
};