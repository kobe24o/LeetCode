class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2 == 0)
        	return NULL;
        vector<TreeNode*> ans;
        TreeNode *root = new TreeNode(0);
        root->left = bt(N-3,ans);
        root->right = bt(N-3,ans);
        return ans;
    }
    TreeNode* bt(int N,vector<TreeNode*> &ans)
    {
    	if(N == 0)
		{
			ans.push_back()
			return NULL;
		}
    }
};