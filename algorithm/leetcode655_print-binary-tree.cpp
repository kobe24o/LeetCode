class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int width = (2<<(height-1))-1;
        vector<vector<string>> ans(height,vector<string> (width,""));
        dfs(ans,root,0,0,width-1);
        return ans;
    }

    int getHeight(TreeNode* root)
    {
    	if(root == NULL)
    		return 0;
    	return max(getHeight(root->left),getHeight(root->right))+1;
    }

    void dfs(vector<vector<string>> &ans, TreeNode* root, int f, int L, int R)
    {
    	if(root == NULL)
    		return;
    	int mid = ((L+R)>>1);
    	ans[f][mid] = to_string(root->val);
    	dfs(ans,root->left,f+1,L,mid-1);
    	dfs(ans,root->right,f+1,mid+1,R);
    }
};