class Solution {
	int i = 0;
	bool can = true;
	vector<int> ans;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    	dfs(root, voyage);
    	if(!can) return {-1};
    	return ans;
    }

    void dfs(TreeNode* root, vector<int>& voyage)
    {
    	if(!can || !root)
    		return;
    	if(root->val == voyage[i])
    	{
    		i++;
    		if(root->left && root->left->val == voyage[i])
    		{
				dfs(root->left, voyage);
				dfs(root->right, voyage);
    		}
    		else if(root->right && root->right->val == voyage[i])
    		{
                if(root->left)
    			    ans.push_back(root->val);
    			dfs(root->right, voyage);
    			dfs(root->left, voyage);
    		}
    		else if(root->left || root->right)
    			can = false;
    	}
    	else
    		can = false;
    }
};