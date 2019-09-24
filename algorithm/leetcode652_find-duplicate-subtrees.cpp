class Solution {
	unordered_map<string, vector<TreeNode*>> m;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == NULL)
        	return {};
        vector<TreeNode*> ans;
        dfs(root);
        for(auto it = m.begin(); it != m.end(); ++it)
        {
        	if(it->second.size() != 1)
        		ans.push_back(it->second.front());
        }
        return ans;
    }
    string dfs(TreeNode* root) 
    {
        if(root == NULL)
            return "E";
    	string str = to_string(root->val)+dfs(root->left)+dfs(root->right);
    	m[str].push_back(root);
    	return str;
    }
};