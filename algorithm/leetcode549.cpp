class Solution {
	unordered_map<TreeNode*, vector<int>> dp; 
	int maxlen = 0;
public:
    int longestConsecutive(TreeNode* root) {
    	dfs(root);
    	return maxlen;
    }
    void dfs(TreeNode* root)
    {
    	if(!root) return;
    	dfs(root->left);
    	dfs(root->right);
    	dp[root] = {1,1};//上升，下降，的最大长度
    	if(root->left)
    	{
    		if(root->val == root->left->val+1)//左侧上升
    			dp[root][0] = max(dp[root][0], dp[root->left][0]+1);
    		if(root->val == root->left->val-1)//左侧下降
    			dp[root][1] = max(dp[root][1], dp[root->left][1]+1);
    	}
    	if(root->right)
    	{
    		if(root->val == root->right->val+1)//右侧上升
    			dp[root][0] = max(dp[root][0], dp[root->right][0]+1);
    		if(root->val == root->right->val-1)//右侧下降
    			dp[root][1] = max(dp[root][1], dp[root->right][1]+1);
    	}
    	maxlen = max(maxlen, dp[root][0]+dp[root][1]-1);
    			//以该节点为升降的和，-1为该节点重复计算1次
    }
};