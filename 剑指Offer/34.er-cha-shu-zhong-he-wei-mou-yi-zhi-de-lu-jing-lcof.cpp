class Solution {
	vector<vector<int>> ans;
	vector<int> temp;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
        	return {};
        dfs(root,sum,0);
        return ans;
    }

    void dfs(TreeNode* root, int& sum, int s)
    {
    	if(root && !root->left && !root->right)
    	{
    		if(s+root->val == sum)
    		{
    			temp.push_back(root->val);
    			ans.push_back(temp);
    			temp.pop_back();
    		}
    		return;
    	}
    	temp.push_back(root->val);
    	if(root->left)
    		dfs(root->left,sum,s+root->val);
    	if(root->right)
    		dfs(root->right,sum,s+root->val);
    	temp.pop_back();
    }
};