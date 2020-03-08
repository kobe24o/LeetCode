class Solution {
	int maxSum = 0;
public:
    int maxSumBST(TreeNode* root) {
    	dfs(root);
    	return maxSum;
    }

    vector<int> dfs(TreeNode* root) 
    {
    	if(!root)
    		return {true,INT_MAX,INT_MIN,0};
    	//子树是不是二叉搜索树 vec[0]
		//子树的最小值 vec[1]
		//子树的最大值 vec[2]
		//子树的sum值 vec[3]
		auto Lstate = dfs(root->left);
		auto Rstate = dfs(root->right);
		if(!Lstate[0] || !Rstate[0] || Lstate[2] >= root->val 
						|| Rstate[1] <= root->val)
			return {false,INT_MAX,INT_MIN,0};//后三个参数随意

		//是二叉搜索树
        int Lmin = root->left ? Lstate[1] : root->val;
        int Rmax = root->right ? Rstate[2] : root->val;
		int cursum = root->val+Lstate[3]+Rstate[3];
		maxSum = max(maxSum, cursum);
		return {true,Lmin,Rmax,cursum};
    }
};