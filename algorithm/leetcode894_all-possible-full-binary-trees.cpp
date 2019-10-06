class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2 == 0)
        	return NULL;
        vector<TreeNode*> ans;
        TreeNode *root = new TreeNode(0);
        ans.push_back(root);
        bt(N-1,ans,root)
        return ans;
    }
    TreeNode* bt(int N,vector<TreeNode*> &ans, TreeNode *root)
    {
    	if(N <= 0)
		{
            if(N == 0)
			 ans.push_back()
			return NULL;
		}
    }
};