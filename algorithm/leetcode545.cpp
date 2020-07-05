class Solution {
	vector<int> ans;
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
    	if(!root) return {};
    	ans.push_back(root->val);
    	dfs(root->left, -1);
    	dfs(root->right, 1);
    	return ans;
    }
    void dfs(TreeNode* root, int dir)
    {
    	if(!root) return;
    	if(dir == -1)
    	{
    		ans.push_back(root->val);//前序遍历
    		if(root->left)
    		{	
    			dfs(root->left,-1);
    			dfs(root->right, 0);
    		}
    		else
    			dfs(root->right,-1);
    	}
    	else if(dir == 1)
    	{
    		// ans.push_back(root->val);//写这里错了
    		if(root->right)
    		{
    			dfs(root->left,0);
    			dfs(root->right, 1);
    		}
    		else
    			dfs(root->left, 1);
    		ans.push_back(root->val);//应该是后序遍历
    	}
    	else//dir==0，非左右边界，找叶子节点
    	{
    		if(!root->left && !root->right)
    			ans.push_back(root->val);
    		dfs(root->left, 0);
    		dfs(root->right, 0);
    	}
    }
};