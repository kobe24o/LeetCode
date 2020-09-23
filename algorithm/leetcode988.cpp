class Solution {
	vector<string> ans;
public:
    string smallestFromLeaf(TreeNode* root) {
    	string path;
    	dfs(root, path);
    	for(string& s : ans)
    		reverse(s.begin(),s.end());
    	sort(ans.begin(), ans.end());
    	return ans[0];
    }
    void dfs(TreeNode* root, string& path) 
    {
    	if(!root) return;
        path += root->val+'a';
    	if(!root->left && !root->right)
    	{
    		ans.push_back(path);
            path.pop_back();
    		return;
    	}
    	dfs(root->left, path);
    	dfs(root->right, path);
    	path.pop_back();
    }
};