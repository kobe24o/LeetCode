class Solution {
	int ans = 0;
public:
    int longestZigZag(TreeNode* root) {
    	if(!root)
    		return 0;
    	dfs(root->left,0,0);
    	dfs(root->right,0,1);
    	return ans;
    }

    void dfs(TreeNode* root, int count, bool dir)
    {
    	if(!root) 
    	{
    		ans = max(ans,count);
    		return;
    	}
    	if(dir)//前一个是右节点
    	{
    		dfs(root->left,count+1,0);
    		dfs(root->right,0,1);
    	}
    	else//前一个是左节点
    	{
    		dfs(root->left,0,0);
    		dfs(root->right,count+1,1);
    	}
    }
};